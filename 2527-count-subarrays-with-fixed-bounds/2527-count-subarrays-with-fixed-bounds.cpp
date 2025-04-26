class Solution {
public:
    long long countSubarrays(vector<int>& nums, int minK, int maxK) {
        long long valid_subarrays = 0;
        int invalid_idx = -1;
        int mink_idx = -1;
        int maxk_idx = -1;

        for(int i=0;i<nums.size(); i++){
            if(nums[i]<minK || nums[i]>maxK) invalid_idx = i;

            if(nums[i]==minK) mink_idx = i;
            if(nums[i]==maxK) maxk_idx = i;

            int count = max(min(maxk_idx, mink_idx) - invalid_idx, 0);
            valid_subarrays += count;
        }
        return valid_subarrays;
    }
};