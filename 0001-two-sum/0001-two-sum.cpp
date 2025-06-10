class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n = nums.size();
        vector<int> ans;
        unordered_map<int,int> mp;

        for(int i=0; i<n; i++){
            int needed = target - nums[i];
            if(mp.count(needed)){
                ans.push_back(mp[needed]);
                ans.push_back(i);
            }
            mp[nums[i]] = i;
        }
        return ans;
    }
};