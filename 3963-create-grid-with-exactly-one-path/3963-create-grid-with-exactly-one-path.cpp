class Solution {
public:
    vector<string> createGrid(int m, int n) {
        vector<string> grid;

        grid.push_back(string(n, '.'));
        string row = string(n-1, '#') + '.';

        for(int i = 1; i<m; i++){
            grid.push_back(row);
        }

        return grid;
    }
};