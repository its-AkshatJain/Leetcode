class Solution {
public:
    bool checkDivisibility(int n) {
        int m = n;
        int sum = 0;
        int product = 1;

        while(m){
            int digit = m%10;
            sum += digit;
            product *= digit;
            m = m/10;
        }

        return n % (sum + product) == 0 ? true : false;
    }
};