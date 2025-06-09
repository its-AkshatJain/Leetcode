class Solution {
    int countNum(long long curr, long long next, int n){
        int count = 0;

        while(curr <= n){
            count += (next - curr);
            curr *= 10;
            next *= 10;

            next = min(next, (long long)(n+1));
        }
        return count;
    }
public:
    int findKthNumber(int n, int k) {
        int curr = 1;
        k -= 1;

        while(k>0){
            int count = countNum(curr, curr+1, n);
            if(count<=k){
                curr++;
                k-=count;
            }else{
                curr *= 10;
                k -=1;
            }
        }
        return curr;
    }
};