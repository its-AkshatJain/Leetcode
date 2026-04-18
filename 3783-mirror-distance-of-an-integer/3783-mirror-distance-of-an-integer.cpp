class Solution {
public:
    int mirrorDistance(int n) {
        int N = n;
        int rev = 0;
        while(N){
            int digit = N%10;
            rev = rev*10 + digit;
            N = N/10;
        }

        return abs(n - rev);
    }
};