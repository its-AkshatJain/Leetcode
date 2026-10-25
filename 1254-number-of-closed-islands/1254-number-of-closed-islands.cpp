class Solution {
public:
    int m, n;
    bool dfs(vector<vector<int>>& grid, int r, int c,
             vector<vector<bool>>& visited) {
        if (r < 0 || r >= m || c < 0 || c >= n) {
            return false; // Not closed
        }

        if (grid[r][c] == 1) {
            return true;
        }

        if (visited[r][c]) {
            return true;
        }

        visited[r][c] = 1; // mark visited

        bool left = dfs(grid, r, c - 1, visited);
        bool right = dfs(grid, r, c + 1, visited);
        bool top = dfs(grid, r - 1, c, visited);
        bool down = dfs(grid, r + 1, c, visited);

        return left && right && top && down;
    }

    int closedIsland(vector<vector<int>>& grid) {
        m = grid.size();
        n = grid[0].size();
        vector<vector<bool>> visited(m, vector<bool>(n, false));

        int count = 0;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 0 && !visited[i][j]) {
                    count += dfs(grid, i, j, visited);
                }
            }
        }

        return count;
    }
};