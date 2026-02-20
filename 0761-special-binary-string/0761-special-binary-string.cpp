class Solution {
public:
    string makeLargestSpecial(string s) {
        int sum = 0;
        int start = 0;
        vector<string> specials;

        for(int i=0; i<s.length(); i++){
            sum += s[i] == '1' ? 1 : -1;
            if(sum == 0){
                string inner = s.substr(start+1, i-start-1);
                specials.push_back("1" + makeLargestSpecial(inner) + "0");
                start = i+1;
            }
        }

        sort(specials.begin(), specials.end(), greater<string>());

        string result;
        for(string &str: specials){
            result += str;
        }

        return result;
    }
};