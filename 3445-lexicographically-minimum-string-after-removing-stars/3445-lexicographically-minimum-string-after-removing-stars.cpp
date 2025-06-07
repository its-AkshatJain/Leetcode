class Solution {
public:
    string clearStars(string s) {
        vector<vector<int>> char_pos(26);

        for(int i=0; i<s.size(); i++){
            if(s[i] == '*'){
                for(int i=0; i<26; i++){
                    if(char_pos[i].size() > 0){
                        s[char_pos[i].back()] = '*';
                        char_pos[i].pop_back();
                        break;
                    }
                }
            }else{
                char_pos[s[i] - 'a'].push_back(i);
            }
        }

        string res;
        for(char ch: s){
            if(ch != '*'){
                res.push_back(ch);
            }
        }
        return res;
    }
};