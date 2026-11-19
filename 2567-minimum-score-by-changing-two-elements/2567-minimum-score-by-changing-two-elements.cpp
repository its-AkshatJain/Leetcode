class Solution {
public:
    int minimizeSum(vector<int>& nums) {
        int n = nums.size();
        if(n <= 3) return 0;

        sort(nums.begin(), nums.end());
        
        int minScore = INT_MAX;
        
        // Take first 2 smallest as same
        minScore = min(minScore, nums[n-1] - nums[2]);
        // Take first smallest and largest element as same
        minScore = min(minScore, nums[n-2] - nums[1]);
        // Take last 2 largest element as same
        minScore = min(minScore, nums[n-3] - nums[0]);

        return minScore;
    }
};