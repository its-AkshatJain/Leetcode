class Solution {
public:
    vector<int> validSequence(string word1, string word2) {
        int m = word1.length();
        int n = word2.length();
        vector<int> last(n, 0);
        int j = n - 1;
        for (int i = m - 1; i >= 0; i--) {
            if (j >= 0 && word1[i] == word2[j]) {
                last[j] = i;
                j--;
            }
        }

        vector<int> res;
        int skip  = 0;
        j = 0;
        for (int i = 0; i < m; i++) {
            if (j == n)
                break;
            if (word1[i] == word2[j] ||
                (skip == 0 && (j == n - 1 || i < last[j + 1]))) {
                if (word1[i] != word2[j])
                    skip += 1;
                res.push_back(i);
                j++;
            }
        }

        return j == n ? res : vector<int>();
    }
};