class Solution {
public:
    int maxDifference(string s) {
        int n = s.size();
        vector<int> freq(26,0);
        for(int i=0; i<n; i++){
            freq[s[i] - 'a']++;
        }

        int maxOdd = INT_MIN;
        int minEven = INT_MAX;
        for(int i=0; i<26; i++){
            if(freq[i] == 0) continue;

            if(freq[i]%2 == 0){
                minEven = min(minEven, freq[i]);
            }else{
                maxOdd = max(maxOdd, freq[i]);
            }
        }
        
        return maxOdd - minEven;
    }
};