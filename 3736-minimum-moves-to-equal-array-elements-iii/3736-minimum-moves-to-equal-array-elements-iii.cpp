class Solution {
public:
    int minMoves(vector<int>& nums) {
        int n = nums.size();
        int mx_element = *max_element(nums.begin(), nums.end());
        int sum = accumulate(nums.begin(), nums.end(), 0);

        return n*mx_element - sum;
    }
};