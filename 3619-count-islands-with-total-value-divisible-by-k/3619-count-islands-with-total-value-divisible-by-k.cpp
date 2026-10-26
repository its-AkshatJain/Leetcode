class Solution {
public:
    int m, n;
    vector<vector<int>> directions = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

    long long bfs(int r, int c, vector<vector<int>>& grid) {
        queue<pair<int, int>> q;
        long long sum = grid[r][c];
        q.push({r, c});
        grid[r][c] = 0;

        while (!q.empty()) {
            auto [i, j] = q.front();
            q.pop();

            for (auto dir : directions) {
                int new_i = i + dir[0];
                int new_j = j + dir[1];

                if (new_i >= 0 && new_i < m && new_j >= 0 && new_j < n &&
                    grid[new_i][new_j] > 0) {
                    sum += grid[new_i][new_j];
                    grid[new_i][new_j] = 0;
                    q.push({new_i, new_j});
                }
            }
        }

        return sum;
    }

    int countIslands(vector<vector<int>>& grid, int k) {
        m = grid.size();
        n = grid[0].size();

        int count = 0;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] > 0) {
                    long long sum = bfs(i, j, grid);
                    if (sum % k == 0) {
                        count++;
                    }
                }
            }
        }

        return count;
    }
};