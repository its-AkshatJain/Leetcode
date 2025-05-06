class Solution {
    int dp[1005][1005];
    int MOD = 1e9 + 7;
    int numTilingWays(int r1, int r2){
        if(r1 == 0 && r2 == 0){
            return 1; //valid tiling
        }
        if(r1<=0 || r2<=0) return 0; //invalid
        if(dp[r1][r2] != -1) return dp[r1][r2];

        long long count = 0;
        if(r1 == r2){
            count+= numTilingWays(r1-2, r2-2); //H
            count+= numTilingWays(r1-1, r2-1); //V             
            count+= numTilingWays(r1-2, r2-1); //inverted mirrored L
            count+= numTilingWays(r1-1, r2-2); // mirrored L
        }else if(r1>r2){
            count+= numTilingWays(r1-2, r2); //H row1
            count+= numTilingWays(r1-2, r2-1); // mirrored L
        }else{
            count+= numTilingWays(r1, r2-2); //H row2
            count+= numTilingWays(r1-1, r2-2); // mirrored L
        }
        return dp[r1][r2] = count%MOD;
    }
public:
    int numTilings(int n) {
       memset(dp, -1, sizeof(dp));
       return numTilingWays(n,n); 
    }
};
