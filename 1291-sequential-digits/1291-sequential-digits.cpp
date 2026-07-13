class Solution {
public:
    vector<int> sequentialDigits(int low, int high) {
        string s = "123456789";
        int minLen = to_string(low).size();
        int maxLen = to_string(high).size();
        vector<int> result;

        for (int len = minLen; len <= maxLen; len++) {
            for (int i = 0; i + len <= 9; i++) {
                int num = stoi(s.substr(i, len));

                if (num >= low && num <= high) {
                    result.push_back(num);
                }
            }
        }

        return result;
    }
};