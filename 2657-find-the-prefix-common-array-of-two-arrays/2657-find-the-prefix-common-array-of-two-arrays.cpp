class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
        int n = A.size();
        vector<int> result;
        unordered_map<int, int> freq;

        for(int i=0; i<n; i++){
            freq[A[i]]++;
            freq[B[i]]++;
            int count = 0; 
            for(auto& it: freq){
                if(it.second > 1){
                    count++;
                }
            }
            result.push_back(count);
        }

        return result;
    }
};