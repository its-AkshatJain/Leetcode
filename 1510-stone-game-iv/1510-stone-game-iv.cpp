class Solution {
public:
    bool solve(int n, vector<int>& t) {
        if (n == 0) {
            return false;
        }

        if (t[n] != -1) {
            return t[n];
        }

        for (int k = 1; k * k <= n; k++) {
            if (solve(n - (k * k), t) == false) { // Check for Bob
                return t[n] = true;                      // Alice wins
            }
        }

        return t[n] = false;
    }

    bool winnerSquareGame(int n) {
        vector<int> t(n+1, -1);
        return solve(n, t);
    }
};