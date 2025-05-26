class Solution {
public:
    bool isPalindrome(int x) {
        if(x<0) return false;
        int num = x;
        long long reverse = 0;
        while(num != 0){
            int digit = num%10;
            reverse = (reverse * 10) + digit; 
            num = num/10;
        }

        if(reverse == x){
            return true;
        }
        return false;
    }
};