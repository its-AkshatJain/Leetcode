class Solution {
public:
    int longestSubsequence(vector<int>& nums) {
        int n = nums.size();
        int allZero = true;
        int totalXor = 0;

        for(int i=0; i<n; i++){
            totalXor ^= nums[i];

            if(nums[i] != 0){
                allZero = false;
            }
        }

        if(allZero){
            return 0;
        }

        return totalXor == 0 ? n-1 : n;
    }
};