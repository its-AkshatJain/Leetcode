class Solution {
public:
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
        int rows = grid.size();
        int cols = grid[0].size();

        int n = rows * cols;
        k = k % n;

        if (k == 0) {
            return grid;
        }

        auto reverse =
            [&](int i, int j) {
                while (i < j) {
                    swap(grid[i / cols][j % cols], grid[j / cols][i % cols]);
                    i++;
                    j--;
                }
            };

        reverse(0, n - 1);
        reverse(0, k - 1);
        reverse(k, n - 1);

        return grid;
    }
};