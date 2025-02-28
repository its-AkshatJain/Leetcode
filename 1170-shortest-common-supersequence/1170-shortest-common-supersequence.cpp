class Solution {
public:
    string shortestCommonSupersequence(string s1, string s2) {
        // find the LCS of s1 and s2
        string lcs = getLCS(s1, s2);
        int i = 0, j = 0;
        string result = "";
        // merge s1 and s2 with the LCS
        for (char c : lcs) {
            // add characters from s1 until the LCS character is found
            while (s1[i] != c) {
                result += s1[i];
                i++;
            }
            // add characters from s2 until the LCS character is found
            while (s2[j] != c) {
                result += s2[j];
                j++;
            }
            // add the LCS character
            result += c;
            i++;
            j++;
        }
        // add any remaining characters from s1 and s2
        result += s1.substr(i) + s2.substr(j);
        // return the merged string
        return result;
    }

    // helper method to find the LCS of two strings
    string getLCS(string s1, string s2) {
        int m = s1.length(), n = s2.length();
        vector<vector<int>> dp(m+1, vector<int>(n+1));
        // fill the dp array using dynamic programming
        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                if (s1[i-1] == s2[j-1]) {
                    dp[i][j] = 1 + dp[i-1][j-1];
                } else {
                    dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
                }
            }
        }
        // backtrack from the bottom right corner of the dp array to find the LCS
        string lcs = "";
        int i = m, j = n;
        while (i > 0 && j > 0) {
            if (s1[i-1] == s2[j-1]) {
                lcs = s1[i-1] + lcs;
                i--;
                j--;
            } else if (dp[i-1][j] > dp[i][j-1]) {
                i--;
            } else {
                j--;
            }
        }
        return lcs;
    }
};