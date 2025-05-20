class Solution {
public:
    bool isZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size();
        vector<int> diff(n+1, 0);

        for(auto q: queries){
            int start = q[0];
            int end = q[1];

            diff[start] += 1;
            diff[end+1] -= 1;
        }

        int sum = 0;
        for(int i=0; i<n; i++){
            sum += diff[i];
            if(sum<nums[i]){
                return false;
            }
        }

        return true;
    }
};