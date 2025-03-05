class Solution {
    int fibChainLen(vector<int>& arr, int a, int b, int n){
        int fib_idx = lower_bound(arr.begin(), arr.end(), a+b) - arr.begin();
        if(fib_idx < n and arr[fib_idx]==a+b){
            return 1+fibChainLen(arr, b, a+b, n);
        }
        return 0;
    }
public:
    int lenLongestFibSubseq(vector<int>& arr) {
        int longest = 0;
        int n = arr.size();

        for(int i=0; i<n-1; i++){
            for(int j=i+1; j<n; j++){
                int a = arr[i];
                int b = arr[j];
                int fib_len = fibChainLen(arr, a, b, n);
                if(fib_len>0){
                    longest = max(longest, 2+fib_len);
                }
            }
        }
        return longest;
    }
};