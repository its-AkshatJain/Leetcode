class Solution {
public:
    vector<int> closestPrimes(int left, int right) {
        vector<int> prime;

        // Ensure we never consider 1 as a prime number
        if (left < 2) left = 2; 

        for(int i=left; i<=right; i++){
            bool isPrime = true;
            for(int j=2; j*j<=i; j++){
                if(i%j == 0){
                    isPrime = false;
                    break;
                }            
            }
            if(isPrime == true){
                prime.push_back(i);
            }
        }

        int a = 0;
        int b = INT_MAX;
        for(int i=1; i<prime.size(); i++){
            if(b-a > prime[i]-prime[i-1]){
                b = prime[i];
                a = prime[i-1];
            }
        }

        vector<int> ans;
        if(a == 0) return ans = {-1, -1};
        else ans = {a,b};
        return ans;
    }
};