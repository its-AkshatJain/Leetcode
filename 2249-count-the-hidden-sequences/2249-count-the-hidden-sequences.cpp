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

        long long start = lower - minPrefix;
        long long end = upper - maxPrefix;

        if(start > end) return 0;
        return end-start+1;
    }
};