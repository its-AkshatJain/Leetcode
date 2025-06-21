class Solution {
public:
    int minimumDeletions(string word, int k) {
        vector<int> freq(26, 0);

        for(int i=0; i<word.size(); i++){
            freq[word[i]-'a']++;
        }
        sort(freq.begin(), freq.end());

        int result = word.size();
        int cumulativeDel = 0;

        for(int i=0; i<26; i++){
            int del = cumulativeDel;
            for(int j=25; j>i; j--){
                if(freq[j] - freq[i] <= k){
                    break;
                }

                del += freq[j]-freq[i]-k; 
            }
            result = min(result, del);
            cumulativeDel += freq[i];
        }
        return result;
    }
};