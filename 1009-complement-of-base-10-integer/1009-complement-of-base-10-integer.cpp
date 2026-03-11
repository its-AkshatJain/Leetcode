class Solution {
public:
    int bitwiseComplement(int n) {
        if(n==0){
            return 1;
        }
        
        int bits = floor(log2(n)) + 1;
        int mask = pow(2, bits) - 1;

        return mask ^ n;
    }
};