class Solution {
public:
    int minMoves(vector<int>& nums) {
        int n = nums.size();
        int max_element = INT_MIN;

        for(int i=0; i<n; i++){
            max_element =  max(max_element, nums[i]);
        }

        int moves = 0;
        for(int i=0; i<n; i++){
            moves += (max_element - nums[i]);
        }

        return moves;
    }
};