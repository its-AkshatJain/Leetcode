class Solution {
public:
    int reverseDegree(string s) {
        int n = s.length();
        int result = 0;

        for(int i=0; i<n; i++){
            int revIdx = 26 - (s[i] - 'a');
            result += revIdx * (i+1);
        }

        return result;
    }
};