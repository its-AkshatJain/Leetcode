class Solution {
    string runLenEncoding(string s){
        string result = "";
        int i=0;

        while(i<s.size()){
            char currChar = s[i];
            int count = 0;

            while(i<s.size() && s[i] == currChar){
                count++;
                i++;
            }

            result += to_string(count) + currChar;
        }
        return result;
    }
public:
    string countAndSay(int n) {
        if(n==1) return "1";
        string res = "1";
        for(int i=1; i<n; i++){
            res = runLenEncoding(res);
        }
        return res;
    }
};