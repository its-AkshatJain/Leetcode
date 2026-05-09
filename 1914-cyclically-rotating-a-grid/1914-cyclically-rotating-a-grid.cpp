class Solution {
public:
    vector<vector<int>> rotateGrid(vector<vector<int>>& grid, int k) {
        int m = grid.size();
        int n = grid[0].size();

        int layers = min(m, n)/2;

        for(int layer = 0; layer<layers; layer++){
            int top = layer;
            int bottom = m-layer-1;
            int left = layer;
            int right = n-layer-1;
            vector<int> nums;

            for(int j=left; j<=right; j++){
                nums.push_back(grid[top][j]);
            }

            for(int i=top+1; i<bottom; i++){
                nums.push_back(grid[i][right]);
            }

            for(int j=right; j>=left; j--){
                nums.push_back(grid[bottom][j]);
            }

            for(int i=bottom - 1; i>top; i--){
                nums.push_back(grid[i][left]);
            }

            int len = nums.size();
            int normalised_k = k%len;
            rotate(nums.begin(), nums.begin()+normalised_k, nums.end());
            int idx = 0;

            for(int j=left; j<=right; j++){
                grid[top][j] = nums[idx++];
            }

            for(int i=top+1; i<bottom; i++){
               grid[i][right] = nums[idx++];
            }

            for(int j=right; j>=left; j--){
                grid[bottom][j] = nums[idx++];
            }

            for(int i=bottom - 1; i>top; i--){
                grid[i][left] = nums[idx++];
            }  
        }

        return grid;
    }
};