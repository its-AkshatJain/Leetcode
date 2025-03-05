class Solution {
public:
    int maxSumSubarrayKadane(vector<int>& nums){
        int currSum = 0;
        int maxSum = INT_MIN;

        for(int i=0; i<nums.size(); i++){
            currSum += nums[i];
            maxSum = max(maxSum, currSum);
            if(currSum<0){
                currSum = 0;
            }
        }
        return maxSum;
    }
    int maxAbsoluteSum(vector<int>& nums) {
        int max_sum_subarray = maxSumSubarrayKadane(nums);

        for(int i=0; i<nums.size(); i++){
            nums[i] = (-1)*nums[i];
        }
        int min_sum_subarray = maxSumSubarrayKadane(nums);
        return max(max_sum_subarray, min_sum_subarray);
    }
};