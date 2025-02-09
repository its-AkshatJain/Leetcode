class Solution {
public:
    long long countBadPairs(vector<int>& nums) {
        long long n = nums.size();

        unordered_map<int, int> freq;
        long long good_pairs = 0;
        for(int i=0; i<n; i++){
            if(freq.count(nums[i] - i)){
                good_pairs += freq[nums[i] - i];
            }
            freq[nums[i] - i]++;
        }
        long long bad_pairs = n*(n-1)/2 - good_pairs;
        return bad_pairs;
    }
};