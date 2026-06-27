class Solution {
public:
    int maximumLength(vector<int>& nums) {
        unordered_map<long long, int> freq;
        int ans = 1;

        for (int& num : nums) {
            freq[num]++;
        }

        if (freq.count(1)) {
            ans = max(ans, freq[1] % 2 == 0 ? freq[1] - 1 : freq[1]);
        }

        for (auto& [x, cnt] : freq) {
            if (x == 1)
                continue;
            long long curr = x;
            int len = 0;

            while (freq.count(curr) && freq[curr] >= 2) {
                len += 2;
                if (curr > 1e9)
                    break;
                curr = curr * curr;
            }

            if (freq.count(curr)) {
                len += 1;
            } else {
                len -= 1;
            }

            ans = max(ans, len);
        }

        return ans;
    }
};