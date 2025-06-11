class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        vector<int> positive, negative;
        for(int i=0; i<nums.size(); i++){
            if(nums[i] < 0){
                negative.push_back(nums[i]);
            }else{
                positive.push_back(nums[i]);
            }
        }

        vector<int> ans;
        for(int i=0; i<positive.size(); i++){
            ans.push_back(positive[i]);
            ans.push_back(negative[i]);
        }
        return ans;
    }
};