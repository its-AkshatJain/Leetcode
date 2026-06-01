class Solution {
public:
    int minimumCost(vector<int>& cost) {
        int n = cost.size();
        sort(cost.begin(), cost.end(), [](int a, int b) { return a > b; });

        int result = 0;
        for (int i = 0; i < n; i++) {
            if ((i + 1) % 3 == 0) {
                continue;
            }
            result += cost[i];
        }

        return result;
    }
};