class Solution {
public:
    int partitionArray(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        
        int minSubsequence = 1;
        int maxi = nums[0]; 
        int mini = nums[0];
        for(int i=1; i<nums.size(); i++){
            maxi = max(maxi, nums[i]); 
            mini = min(mini, nums[i]);

            if(maxi - mini > k){
                minSubsequence++;
                maxi = mini = nums[i];
            }
        }
        return minSubsequence;
    }
};