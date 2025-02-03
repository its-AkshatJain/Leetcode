class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {
        int n = nums.size();
        if(n==1) return 1;
        
        // Strictly increasing
        int cnt1 = 1;
        int max_incr = 0;
        for(int i=1; i<n; i++){
            if(nums[i-1] < nums[i]){
                cnt1 += 1;
            }else{
                max_incr = max(cnt1, max_incr);
                cnt1 = 1;
            }
        }
        max_incr = max(cnt1, max_incr);

        // Strictly decreasing
        int cnt2 = 1;
        int max_decr = 0;
        for(int i=1; i<n; i++){
            if(nums[i-1] > nums[i]){
                cnt2 += 1;
            }else{
                max_decr = max(cnt2, max_decr);
                cnt2 = 1;
            }
        }
        max_decr = max(cnt2, max_decr);

        return max(max_incr, max_decr);
    }
};