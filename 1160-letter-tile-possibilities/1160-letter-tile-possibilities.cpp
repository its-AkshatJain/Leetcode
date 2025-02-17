class Solution {
    int buildString(vector<int> &freq){
        int ways = 0;
        // Any char can be at curr position
        for(int i=0; i<26; i++){
            if(freq[i]>0){
                freq[i]--;
                ways += 1 + buildString(freq);
                freq[i]++;
            }
        }
        return ways;
    }
public:
    int numTilePossibilities(string tiles) {
        vector<int> freq(26,0);
        for(int c: tiles){
            freq[c - 'A']++;
        }
        return buildString(freq);
    }
};