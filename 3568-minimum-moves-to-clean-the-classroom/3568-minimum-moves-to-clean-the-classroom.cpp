class Solution {
public:
    int minMoves(vector<string>& classroom, int energy) {
        int m = classroom.size();
        int n = classroom[0].size();

        int sr = -1, sc = -1;
        vector<pair<int, int>> litter;

        // Find starting position and litter positions
        for (int r = 0; r < m; r++) {
            for (int c = 0; c < n; c++) {

                if (classroom[r][c] == 'S') {
                    sr = r;
                    sc = c;
                }
                else if (classroom[r][c] == 'L') {
                    litter.push_back({r, c});
                }
            }
        }

        int L = litter.size();

        // No litter to collect
        if (L == 0)
            return 0;

        // 111...111 -> all litter collected
        int fullMask = (1 << L) - 1;

        // litterId[r][c] = which bit represents this litter
        vector<vector<int>> litterId(
            m,
            vector<int>(n, -1)
        );

        for (int i = 0; i < L; i++) {
            int r = litter[i].first;
            int c = litter[i].second;

            litterId[r][c] = i;
        }

        /*
            bestEnergy[r][c][mask]

            Maximum energy with which we have reached:
            (r, c) after collecting 'mask'
        */
        vector<vector<vector<int>>> bestEnergy(
            m,
            vector<vector<int>>(
                n,
                vector<int>(1 << L, -1)
            )
        );

        /*
            State:
            row
            col
            mask
            remaining energy
            steps
        */
        queue<tuple<int, int, int, int, int>> q;

        q.push({sr, sc, 0, energy, 0});

        bestEnergy[sr][sc][0] = energy;

        int dir[4][2] = {
            {-1, 0}, // up
            {1, 0},  // down
            {0, -1}, // left
            {0, 1}   // right
        };

        while (!q.empty()) {

            auto [r, c, mask, e, steps] = q.front();
            q.pop();

            // All litter collected
            if (mask == fullMask)
                return steps;

            for (int d = 0; d < 4; d++) {

                int nr = r + dir[d][0];
                int nc = c + dir[d][1];

                // Outside grid
                if (nr < 0 || nr >= m ||
                    nc < 0 || nc >= n) {
                    continue;
                }

                // Cannot walk through obstacle
                if (classroom[nr][nc] == 'X')
                    continue;

                // No energy to make a move
                if (e == 0)
                    continue;

                int ne = e - 1;
                int nmask = mask;

                // If we step on litter
                if (classroom[nr][nc] == 'L') {

                    int id = litterId[nr][nc];

                    nmask |= (1 << id);
                }

                // If we step on reset area
                if (classroom[nr][nc] == 'R') {
                    ne = energy;
                }

                /*
                    If we have already reached this
                    (position + mask) with MORE energy,
                    this state is useless.
                */
                if (ne <= bestEnergy[nr][nc][nmask])
                    continue;

                bestEnergy[nr][nc][nmask] = ne;

                q.push({
                    nr,
                    nc,
                    nmask,
                    ne,
                    steps + 1
                });
            }
        }

        return -1;
    }
};