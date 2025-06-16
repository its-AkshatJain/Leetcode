class Solution {
public:
    int maximumDifference(vector<int>& nums) {
        int n = nums.size();
        int maxDiff = -1;
        int minEle = nums[0];

        for(int j = 1; j<n; j++){
            if(nums[j] > minEle){
                maxDiff = max(maxDiff, nums[j] - minEle);
            }else{
                minEle = nums[j];
            }
        }
        return maxDiff;
    }
};