class Solution {
public:
    bool checkHammingOne(string& s1, string& s2){
        int diff = 0;
        for(int i=0; i<s1.size(); i++){
            if(s1[i] != s2[i]){
                diff++;
            }
            if(diff>1){
                return false;
            }
        }
        return diff == 1;
    }

    vector<string> getWordsInLongestSubsequence(vector<string>& words, vector<int>& groups) {
        int n = words.size();
        vector<int> dp(n,1);
        vector<int> parent(n,-1);
        int longestSub = 1;
        int longestSubIndex = 0;

        for(int i=0; i<n; i++){
            for(int j=0; j<i; j++){
                if(groups[i]!=groups[j] && words[i].length() == words[j].length() && checkHammingOne(words[i],words[j])){
                    if(dp[j]+1 > dp[i]){
                        dp[i] = dp[j] + 1;
                        parent[i] = j;
                        if(longestSub < dp[i]){
                            longestSub = dp[i];
                            longestSubIndex = i;
                         }
                    }
                }
            }
        }

        vector<string> result;
        while(longestSubIndex != -1){
            result.push_back(words[longestSubIndex]);
            longestSubIndex = parent[longestSubIndex];
        }  

        reverse(begin(result), end(result));
        return result;  
    }
};