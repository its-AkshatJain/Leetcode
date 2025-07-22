class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        int n = nums.size();
        int left = 0;
        int right = 0;
        unordered_set<int> already_taken;
        
        int sum = 0;
        int max_sum = 0;

        while(right < n){
           if(already_taken.count(nums[right])){
                sum -= nums[left];
                already_taken.erase(nums[left]);
                left++;
           }else{
                sum += nums[right];
                already_taken.insert(nums[right]);
                right++;
                max_sum = max(max_sum, sum);
           } 
        }
        return max_sum;
    }
};