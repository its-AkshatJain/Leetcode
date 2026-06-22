class Solution {
public:
    int maxNumberOfBalloons(string text) {
        vector<int> freq(26, 0);
        int ans = 0;
        for (char ch : text) {
            freq[ch - 'a']++;
        }

        while (freq['b' - 'a'] > 0 && freq['a' - 'a'] > 0 && freq['l' - 'a'] > 1 &&
               freq['o' - 'a'] > 1 && freq['n' - 'a'] > 0) {
            ans++;
            freq['b' - 'a']--;
            freq['a' - 'a']--;
            freq['l' - 'a'] -= 2;
            freq['o' - 'a'] -= 2;
            freq['n' - 'a']--;
        }

        return ans;
    }
};