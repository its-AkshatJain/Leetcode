class Solution {
    vector<int> generateRow(int row){
        vector<int> ansRow;
        ansRow.push_back(1);
        long long ans = 1;
        for(int col = 1; col<row; col++){
            ans = ans*(row - col);
            ans = ans/col;
            ansRow.push_back(ans);
        }
        return ansRow;
    }
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> res;
        for(int i=1; i<=numRows; i++){
            res.push_back(generateRow(i));
        }
        return res;
    }
};