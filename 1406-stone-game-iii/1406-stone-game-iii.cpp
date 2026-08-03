class Solution {
public:
    int n;
    int solve(int i, vector<int>& t, vector<int>& stoneValue) {
        if (i >= n) {
            return 0;
        }

        if (t[i] != -1) {
            return t[i];
        }

        int result = stoneValue[i] - solve(i + 1, t, stoneValue);

        if (i + 1 < n) {
            result = max(result, stoneValue[i] + stoneValue[i + 1] -
                                     solve(i + 2, t, stoneValue));
        }
        if (i + 2 < n) {
            result = max(result, stoneValue[i] + stoneValue[i + 1] +
                                     stoneValue[i + 2] -
                                     solve(i + 3, t, stoneValue));
        }
        return t[i] = result;
    }

    string stoneGameIII(vector<int>& stoneValue) {
        n = stoneValue.size();
        vector<int> t(n + 1, -1);

        int diff = solve(0, t, stoneValue);

        if (diff > 0) {
            return "Alice";
        } else if (diff < 0) {
            return "Bob";
        }

        return "Tie";
    }
};