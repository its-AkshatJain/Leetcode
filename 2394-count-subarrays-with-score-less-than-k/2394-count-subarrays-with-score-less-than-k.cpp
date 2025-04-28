class Solution {
public:
    long long countSubarrays(vector<int>& nums, long long k) {
        int n = nums.size();
        int left = 0;
        int right = 0;
        long long window_sum = 0;
        long long count = 0;

        while(left<n){
            while(right<n && ((long long)(window_sum+nums[right])*(right-left+1))<k){
                window_sum += nums[right++];
            }

            count += right - left;

            // Slide window
            if(right == left){
                right++;
            }else{
                window_sum -= nums[left];
            }
            left++;
        }
        return count;
    }
};