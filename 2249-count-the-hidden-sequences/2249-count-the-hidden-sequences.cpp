class Solution {
public:
    int numberOfArrays(vector<int>& differences, int lower, int upper) {
        long long minPrefix = 0;
        long long maxPrefix = 0;
        long long sum = 0;

        for(int diff: differences){
            sum += diff;
            minPrefix = min(minPrefix, sum);
            maxPrefix = max(maxPrefix, sum);
        }
                    // bound - range +1
        int count = (upper-lower) - (maxPrefix - minPrefix) + 1;
        return count>0? count: 0;
    }
};