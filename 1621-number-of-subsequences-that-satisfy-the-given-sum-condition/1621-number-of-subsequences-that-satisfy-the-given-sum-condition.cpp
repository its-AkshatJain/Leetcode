class Solution {
    int MOD = 1e9+7;
    void precomputePowerOfTwo(vector<int> &powerOfTwo, int n){
        powerOfTwo[0] = 1;
        for(int i=1; i<n; i++){
            powerOfTwo[i] = (powerOfTwo[i-1]*2LL)%MOD;
        }
    }
public:
    int numSubseq(vector<int>& nums, int target) {
        int n = nums.size();
        vector<int> powerOfTwo(n);
        precomputePowerOfTwo(powerOfTwo, n);

        sort(nums.begin(), nums.end());
        int subsequences = 0;
        
        int l = 0;
        int r = n-1;
        while(l<=r){
            if(nums[l]+nums[r] > target){
                r--;
            }else{
                subsequences = (subsequences + powerOfTwo[r - l])%MOD;
                l++;
            }
        }
        return subsequences;
    }
};