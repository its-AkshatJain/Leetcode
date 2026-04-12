class Solution {
    int dp[301][7][7][7][7];

    pair<int, int> getCoordinate(char ch){
        int pos = ch - 'A';
        return {pos/6, pos%6};
    }

    int getDist(int x1, int y1, int x2, int y2){
        return abs(x1-x2) + abs(y1-y2);
    }
    int solve(string &word, int i, int x1, int y1, int x2, int y2){
        if(i == word.size()){
            return 0;
        }

        if(dp[i][x1+1][y1+1][x2+1][y2+1] != -1){
            return dp[i][x1+1][y1+1][x2+1][y2+1];
        }

        auto [x, y] = getCoordinate(word[i]);

        if(x1 == -1 && y1 == -1 && x2 == -1 && y2 == -1){
            int moveF = solve(word, i+1, x, y, x2, y2);
            return dp[i][x1+1][y1+1][x2+1][y2+1] = moveF;
        }

        if(x2 == -1 && y2 == -1){
            int moveF2 = solve(word, i+1, x1, y1, x, y);
            int moveF1 = getDist(x1, y1, x, y) + solve(word, i+1, x, y, x2, y2);
            return dp[i][x1+1][y1+1][x2+1][y2+1] = min(moveF1, moveF2);
        }

         int moveF1 = getDist(x1, y1, x, y) + solve(word, i+1, x, y, x2, y2);
         int moveF2 = getDist(x2, y2, x, y) + solve(word, i+1, x1, y1, x, y);
         return dp[i][x1+1][y1+1][x2+1][y2+1] = min(moveF1, moveF2);
    }
public:
    int minimumDistance(string word) {
        memset(dp, -1, sizeof(dp));
        return solve(word, 0, -1, -1, -1, -1);
    }
};