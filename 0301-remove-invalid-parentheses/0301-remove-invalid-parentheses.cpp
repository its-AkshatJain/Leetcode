class Solution {
public:
    int n;
    unordered_set<string> st;
    
    void solve(string &s, int i, string &curr, int count, int &maxLength){
        if(count < 0) return;

        if(i == n){
            if(count == 0){
                if(curr.length() > maxLength){
                    maxLength = curr.length();
                    st.clear();
                }

                if(curr.length() == maxLength){
                    st.insert(curr);
                }
            }
            return;
        }

        if(s[i] != '(' && s[i] != ')'){
            curr.push_back(s[i]);
            solve(s, i+1, curr, count, maxLength);
            curr.pop_back();
            return;
        }

        curr.push_back(s[i]);
        solve(s, i+1, curr, count + (s[i] == '(' ? 1 : -1), maxLength);

        curr.pop_back();

        solve(s, i+1, curr, count, maxLength);
    }

    vector<string> removeInvalidParentheses(string s) {
        n = s.size();

        int maxLength = 0;
        string curr = "";

        solve(s, 0, curr, 0, maxLength);

        return vector<string>(st.begin(), st.end());
    }
};