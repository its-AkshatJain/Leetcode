class Solution {
    int MOD = 1e9 + 7;
public:
    int numTilings(int n) {
       if(n<3) return n;
       vector<int> dp(n+1);

       dp[0] = 1;
       dp[1] = 1;
       dp[2] = 2;

       for(int i=3; i<=n; i++){
         dp[i] = (1LL*2*dp[i-1] + dp[i-3])%MOD; 
       }
       return dp[n]; 
    }
};
