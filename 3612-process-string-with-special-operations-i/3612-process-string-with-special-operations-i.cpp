class Solution {
public:
    string reverseString(string s) {
        int i = 0;
        int j = s.length() - 1;
        while (i < j) {
            swap(s[i], s[j]);
            i++;
            j--;
        }
        return s;
    }
    string processStr(string s) {
        string result = "";
        for (char& ch : s) {
            if (ch == '*') {
                if (!result.empty()) {
                    result.pop_back();
                }
            } else if (ch == '#') {
                result += result;
            } else if (ch == '%') {
                result = reverseString(result);
            } else {
                result += ch;
            }
        }
        return result;
    }
};