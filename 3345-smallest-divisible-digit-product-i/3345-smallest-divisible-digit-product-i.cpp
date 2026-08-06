class Solution {
public:
    int smallestNumber(int n, int t) {
        while (true) {
            int product = 1;

            int m = n;
            while (m) {
                int digit = m % 10;
                product *= digit;
                m = m / 10;
            }

            if (product % t == 0) {
                return n;
            }

            n++;
        }      
    }
};