class Solution {
public:
    long long gcdSum(vector<int>& nums) {
        int n = nums.size();
        int maxPrefix = 0;
        vector<int> prefixGcd(n);

        for(int i=0; i<n; i++){
            maxPrefix = max(maxPrefix, nums[i]);
            prefixGcd[i] = __gcd(nums[i], maxPrefix);
        }

        sort(prefixGcd.begin(), prefixGcd.end());

        int left = 0;
        int right = n-1;
        long long sum = 0;
        while(left < right){
            sum += __gcd(prefixGcd[left], prefixGcd[right]);
            left++;
            right--;
        }

        return sum;
    }
};