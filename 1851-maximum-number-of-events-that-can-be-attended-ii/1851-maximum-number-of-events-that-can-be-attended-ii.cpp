class Solution {
public:
    int maxValue(vector<vector<int>>& events, int k) {
        int n = events.size();
        sort(events.begin(), events.end());

        // Build next array using binary search
        vector<int> next(n, n); // default to n (no next)
        for (int i = 0; i < n; ++i) {
            int lo = i + 1, hi = n - 1;
            while (lo <= hi) {
                int mid = lo + (hi - lo) / 2;
                if (events[mid][0] > events[i][1]) {
                    next[i] = mid;
                    hi = mid - 1;
                } else {
                    lo = mid + 1;
                }
            }
        }

        // DP arrays: prev = dp[j - 1], curr = dp[j]
        vector<int> prev(n + 1, 0);

        for (int j = 1; j <= k; ++j) {
            vector<int> curr(n + 1, 0);
            for (int i = n - 1; i >= 0; --i) {
                int take = events[i][2] + prev[next[i]];
                int skip = curr[i + 1];
                curr[i] = max(take, skip);
            }
            prev = curr;
        }

        return prev[0];
    }
};
