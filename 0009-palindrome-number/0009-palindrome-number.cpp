class Solution {
public:
    bool isPalindrome(int x) {
        if(x<0) return false;

        string s = to_string(x);
        int n = s.size();
        int l=0, r= n-1;

        while(l<=r){
            if(s[l] != s[r]){
                return false;
            }
            l++;
            r--;
        }
        
        return true;
    }
};