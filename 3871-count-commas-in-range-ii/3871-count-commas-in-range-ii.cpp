class Solution {
public:
    typedef long long ll;
    long long countCommas(long long n) {
        ll lower = 1000;
        ll commas = 1;
        ll result = 0;

        while (lower <= n) {
            ll upper = lower * 1000 - 1;
            if (upper > n) {
                upper = n;
            }
            
            ll countNos = upper - lower + 1;

            result += (countNos * commas);
            lower *= 1000;
            commas++;
        }

        return result;
    }
};