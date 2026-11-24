class Solution {
public:
    int maxLength(vector<int>& nums) {
        int n = nums.size();
        int ans = INT_MIN;

        for (int i = 0; i < n; i++) {
            long long product = 1;
            int g = 0;
            int l = 1;

            for (int j = i; j < n; j++) {
                if (product > LLONG_MAX / nums[j]) {
                    break;
                }
                product *= nums[j];

                g = gcd(g, nums[j]);
                l = lcm(l, nums[j]);

                if (product == 1LL * g * l) {
                    ans = max(ans, j - i + 1);
                }
            }
        }

        return ans;
    }
};