class Solution {
public:
    long long sumAndMultiply(int n) {
        int sum = 0;
        int num = 0;
        long long place = 1;

        while (n) {
            int digit = n % 10;
            if (digit != 0) {
                num = digit * place + num;
                place *= 10;
                sum += digit;
            }
            n /= 10;
        }

        return 1LL * num * sum;
    }
};