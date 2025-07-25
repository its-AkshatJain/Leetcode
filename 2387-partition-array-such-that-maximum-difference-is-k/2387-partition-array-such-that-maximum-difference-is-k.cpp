class Solution {
public:
    int partitionArray(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        
        int minSubsequence = 1;
        int start = nums[0]; 
        for(int i=1; i<nums.size(); i++){
            if(nums[i] - start > k){
                minSubsequence++;
                start = nums[i];
            }
        }
        return minSubsequence;
    }
};