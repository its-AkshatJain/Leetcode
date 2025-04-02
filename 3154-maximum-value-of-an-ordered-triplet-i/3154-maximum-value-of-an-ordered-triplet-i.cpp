class Solution {
public:
    long long maximumTripletValue(vector<int>& nums) {
        int n = nums.size();
        if(n < 3) return 0;

        long long maxtriplet = 0, max_i_j = 0, max_i = 0;
        for(int num:nums){
            maxtriplet = max(maxtriplet, max_i_j* (1LL) * num);
            max_i_j = max(max_i_j, max_i - num);
            max_i = max(max_i, (long long)num);
        }

        return maxtriplet;
    }
};