class Solution {
public:
    int subsetXORSum(vector<int>& nums) {
        int n = nums.size();
        int orr = 0;
        for(int num: nums){
            orr |= num;
        }
        return orr*(1<<(n-1));
    }
};