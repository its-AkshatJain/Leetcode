class Solution {
public:
    vector<bool> pathExistenceQueries(int n, vector<int>& nums, int maxDiff,
                                      vector<vector<int>>& queries) {
        vector<bool> ans;
        vector<int> comp(n);
        comp[0] = 0;

        for (int i = 1; i < n; i++) {
            if (nums[i] - nums[i - 1] <= maxDiff)
                comp[i] = comp[i - 1];
            else
                comp[i] = comp[i - 1] + 1;
        }

        for (auto& query : queries) {
            int u = query[0];
            int v = query[1];

            ans.push_back(comp[u] == comp[v]);
        }

        return ans;
    }
};