class Solution {
    using ll = long long;
    int MOD = 1e9+7;

    int binaryExp(ll a, ll b){
        ll res = 1;
        while(b){
            if(b&1) res = (res*a)%MOD;
            
            a = (a*a)%MOD;
            b /= 2;
        }
        return res;
    }
public:
    int countGoodArrays(int n, int m, int k) {
        vector<ll> fact(n+1);
        vector<ll> inv_fact(n+1);

        fact[0] = 1;
        for(int i=1; i<=n; i++){
            fact[i] = (1LL*fact[i-1]*i)%MOD;
        }

        // Fermat Little Theorem
        for(int i=0;i<=n;i++){
            inv_fact[i] = binaryExp(fact[i], MOD-2);
        }

        if (n - 1 - k < 0) return 0;
        ll pair_selection = ((1LL*fact[n-1] * inv_fact[n-1-k])%MOD * inv_fact[k])%MOD;
        ll ways_to_assign = (1LL * m * binaryExp(m-1, n-k-1))%MOD;
        ll result = (pair_selection * ways_to_assign)%MOD;

        return (int)result;
    }
};