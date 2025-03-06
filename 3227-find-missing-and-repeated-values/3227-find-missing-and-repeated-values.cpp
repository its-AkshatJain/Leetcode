class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<int> freq(n*n+1,0);
        vector<int> res;

        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                freq[grid[i][j]]++;
            }
        }
        int a,b;
        for(int i=1; i<=n*n; i++){
            if(freq[i]>1){
                a = i;
            }
            if(freq[i] == 0){
                b = i;
            }
        }
        res.push_back(a);
        res.push_back(b);
        return res;
    }
};