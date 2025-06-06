class Solution {
public:
    int maxAscendingSum(vector<int>& nums) {
       int n = nums.size();
       int sum = nums[0];
       int max_sum = 0;
       for(int i=1; i<n; i++){
          if(nums[i-1] < nums[i]){
            sum += nums[i];
          }else{
            max_sum = max(max_sum, sum);
            sum = nums[i];
          }
       }
       max_sum = max(max_sum, sum); 
       return max_sum;
    }
};