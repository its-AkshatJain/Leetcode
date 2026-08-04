class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        int n = nums.size();
        vector<int> result;

        sort(nums.begin(), nums.end());
        
        for(int i=0; i<n-1; i++){
            for(int x = nums[i]+1; x<nums[i+1]; x++){
                result.push_back(x);
            }
        }

        return result;
    }
};