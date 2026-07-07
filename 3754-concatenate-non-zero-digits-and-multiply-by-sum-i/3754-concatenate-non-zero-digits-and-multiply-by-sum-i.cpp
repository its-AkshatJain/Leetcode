class Solution {
public:
    long long sumAndMultiply(int n) {
        int sum = 0;
        int revNum = 0, num = 0 ;
        
        while(n){
            int digit = n%10;
            if(digit != 0) revNum = revNum*10 + digit;
            n /= 10; 
        }

        while(revNum){
            int digit = revNum%10;
            sum += digit;
            num = num*10 + digit;
            revNum /= 10; 
        }

        return 1LL*num*sum;
    }
};