class Solution {
public:
    int maxFrequency(vector<int>& nums, int k) {
        int n = nums.size();
        sort(nums.begin(), nums.end());

        int l=0, res = 0;
        long long total = 0;

        for(int r=0; r<n; r++){
            total += nums[r];

            while((long long)(nums[r]) * (r-l+1) - total > k){
                total -= nums[l];
                l++;
            }

            res = max(res, r-l+1);
        }
        return res;
    }
};