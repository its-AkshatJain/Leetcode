class Solution {
public:
    long long countSubarrays(vector<int>& nums, int k) {
        int left=0;
        int right=0;
        int count_max=0;
        int n = nums.size();
        long long res = 0;

        int maxi = 0;
        for(int num: nums){
            maxi = max(maxi, num);
        }

        while(right<n){
            if(nums[right]==maxi){
                count_max++;
            }
            
            while(count_max>=k && left<n){
                res += n-right;
                if(nums[left]==maxi){
                    count_max--;
                }
                left++;
            }

            right++;      
        }
        return res;
    }
};