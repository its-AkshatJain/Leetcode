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
        while(i<n){
            int end = lastOccurance[s[i]-'a'];
            int j = i;
            while(j<end){
                end = max(end, lastOccurance[s[j]-'a']);
                j++;
            }
            res.push_back(j-i+1);
            i = j+1;
        }
        return res;
    }
};