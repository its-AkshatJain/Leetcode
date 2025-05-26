class Solution {
public:
    bool isPalindrome(int x) {
        if(x<0 || (x % 10 == 0 && x != 0)) return false;

        int halfReversed = 0;

        while(x>halfReversed){
            halfReversed = (halfReversed*10) + x%10;
            x = x/10;
        }

        // Handle even and odd cases
        return x == halfReversed || x == halfReversed/10;
    }
};