class Solution {
public:
    string mapWordWeights(vector<string>& words, vector<int>& weights) {
        int n = words.size();
        string result = "";

        for (string& word : words) {
            int wordWeight = 0;
            for (char& ch : word) {
                wordWeight += weights[ch - 'a'];
            }
            wordWeight = wordWeight % 26;
            int index = 26 - wordWeight;
            result += 'a' + (index - 1);
        }
        return result;
    }
};