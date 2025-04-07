class Solution {
    bool solve(vector<int>& nums,int i, int target, vector<vector<int>> &dp){
        if(target == 0) return true;
        if(i >= nums.size() || target<0) return false;

        if(dp[i][target] != -1){
            return dp[i][target];
        }

        bool pick = solve(nums, i+1, target - nums[i], dp);
        bool nopick = solve(nums, i+1, target, dp);

        return dp[i][target] = pick || nopick;
    }
public:
    bool canPartition(vector<int>& nums) {
        int n = nums.size();
        int total = 0;
        for(int i=0; i<n; i++){
            total += nums[i];
        }

        if(total%2 != 0) return false;
        int target = total/2;
        vector<vector<int>> dp(n, vector<int>(target+1, -1));

        return solve(nums, 0, target, dp);        
    }
};