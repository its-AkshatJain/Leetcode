class Solution {
public:
    bool areAlmostEqual(string s1, string s2) {
        if(s1 == s2) return true;
        int n = s1.size();

        vector<int> diffIndices;

        for(int i=0; i<n; i++){
            if(s1[i] != s2[i]){
                diffIndices.push_back(i);
            }
        }

        // If differing indices is greater than 2
        if(diffIndices.size() != 2) return false;

        swap(s1[diffIndices[0]], s1[diffIndices[1]]);

        return s1 == s2;
    }
};