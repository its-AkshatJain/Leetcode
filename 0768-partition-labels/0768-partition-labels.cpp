class Solution {
public:
    vector<int> partitionLabels(string s) {
        vector<int> res;
        int n = s.size();

        vector<int> lastOccurance(26,-1);
        for(int i=0; i<n; i++){
            int idx = s[i] - 'a';
            lastOccurance[idx] = i;
        }

        int i = 0;
        int start = 0;
        int end = 0;
        while(i<n){
            end = max(end, lastOccurance[s[i]-'a']);
            
            if(i == end){
                res.push_back(end-start+1);
                start = end+1;
            }
            i++;
        }
        return res;
    }
};