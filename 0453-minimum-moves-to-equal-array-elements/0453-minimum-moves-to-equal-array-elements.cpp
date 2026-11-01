class Solution {
public:
    int minMoves(vector<int>& nums) {
        int n = nums.size();

        int min_element = INT_MAX;
        for(int i=0; i<n; i++){
            min_element = min(min_element, nums[i]); 
        }

        int operations = 0;
        for(int i=0; i<n; i++){
            operations += (nums[i] - min_element);
        }

        return operations;
    }
};