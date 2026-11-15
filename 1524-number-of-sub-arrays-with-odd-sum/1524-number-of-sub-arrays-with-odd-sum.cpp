class Solution {
public:
    int M = 1e9 + 7;
    int numOfSubarrays(vector<int>& arr) {
        int n = arr.size();

        vector<int> prefixSum(n, 0);
        prefixSum[0] = arr[0];

        for (int i = 1; i < n; i++) {
            prefixSum[i] = arr[i] + prefixSum[i - 1];
        }

        int count = 0;
        int odd = 0;
        int even = 1; // taken one as in case when no even element only odd
                      // element is considered as subarray

        for (int i = 0; i < n; i++) {
            if (prefixSum[i] % 2 == 0) {
                count = (count + odd) % M;
                even++;
            } else {
                count = (count + even) % M;
                odd++;
            }
        }

        return count;
    }
};