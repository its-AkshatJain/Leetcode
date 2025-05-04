class Solution {
public:
    int numEquivDominoPairs(vector<vector<int>>& dominoes) {
        unordered_map<int, int> freq;
        for(auto d: dominoes){
            int a = d[0];
            int b = d[1];
            int key = min(a,b)*10 + max(a,b);
            freq[key]++;
        } 
        int pairs = 0;
        for(int i=0; i<freq.size(); i++){
            if(freq[i]>1){
                pairs += (freq[i]*(freq[i]-1))/2;  //(n*(n-1))/2
            }
        }
        return pairs;
    }
};