class Solution {
public:
    int maximumElementAfterDecrementingAndRearranging(vector<int>& arr) {
        int n = arr.size();
        vector<int> count(n + 1, 0);
        for (int x : arr) {
            count[min(x, n)]++;
        }

        int ans = 0;

        for (int x = 1; x <= n; x++) {
            while (count[x]--) {
                ans = min(ans + 1, x);
            }
        }

        return ans;
    }
};