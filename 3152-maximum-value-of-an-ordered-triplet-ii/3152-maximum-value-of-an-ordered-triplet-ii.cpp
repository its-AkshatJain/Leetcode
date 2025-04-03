class Solution {
public:
    long long maximumTripletValue(vector<int>& nums) {
        if(nums.size() < 3) return 0;
        long long max_triplet = 0;
        long long max_i_j = 0, max_i = 0;

        for(int num: nums){
            max_triplet = max(max_triplet, max_i_j*(1LL)*num);
            max_i_j = max(max_i_j, max_i - num);
            max_i = max(max_i, (long long)num);
        }

        return max_triplet;
    }
};