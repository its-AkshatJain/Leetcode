class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        int n = nums.size();
        vector<int> cumSum(n, 0);

        cumSum[0] = nums[0];
        for(int i=1; i<n; i++){
            cumSum[i] = cumSum[i-1] + nums[i];
        }

        vector<int> mp(10001, -1);
        int max_sum = 0; 
        int left = 0;
        int right = 0;

        while(right < n){
           left = max(left, mp[nums[right]]+1);

           int rightSum = cumSum[right];
           int leftSum = (left-1 < 0) ? 0 : cumSum[left-1]; 

           max_sum = max(max_sum, rightSum - leftSum);

           mp[nums[right]] = right;
           right++;
        }
        return max_sum;
    }
};