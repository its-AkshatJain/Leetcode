class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n = nums.size();
        int ind = -1;

        // Calculate break point
        for(int i=n-2; i>=0; i--){
            if(nums[i] < nums[i+1]){
                ind = i;
                break;
            }
        }

        if(ind == -1){
            reverse(nums.begin(), nums.end());
            return;
        }
        // calculate smallest element greater than breaking point element
        for(int i=n-1; i>ind; i--){
            if(nums[i] > nums[ind]){
                swap(nums[i], nums[ind]);
                break;
            }
        }

        // sort the remaing elements or just reverse as increasing order already
        reverse(nums.begin()+ind+1, nums.end());
        return;

    }
};