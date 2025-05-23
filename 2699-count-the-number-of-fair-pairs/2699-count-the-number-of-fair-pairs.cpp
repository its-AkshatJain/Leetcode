class Solution {
public:
    long long countFairPairs(vector<int>& nums, int lower, int upper) {
        int n = nums.size();

        sort(nums.begin(), nums.end());

        long long res = 0;
        for(int i=0; i<n; i++){
            int lb = lower_bound(nums.begin()+i+1, nums.end(), lower - nums[i]) - nums.begin();
            int ub = upper_bound(nums.begin()+i+1, nums.end(), upper - nums[i]) - nums.begin();
            res += ub - lb;
        }
        return res;
    }
};