class Solution {
public:
    long long maxTotalValue(vector<int>& nums, int k) {
        int n = nums.size();
        int maxElement = INT_MIN;
        int minElement = INT_MAX;

        for(int i=0; i<n; i++){
            maxElement = max(maxElement, nums[i]);
            minElement = min(minElement, nums[i]);
        }

        return 1LL * k * (maxElement - minElement);
    }
};