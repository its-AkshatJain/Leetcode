class Solution {
public:
    int maxRotateFunction(vector<int>& nums) {
        int n = nums.size();
        long long F = 0;
        long long sum = 0;

        for(int i=0; i<n; i++){
            sum += nums[i];
            F += i*nums[i];
        }

        long long result = F;

        for(int k=1; k<n; k++){
            F = F + sum - n*nums[n-k];
            result = max(result, F);
        }

        return result;
    }
};