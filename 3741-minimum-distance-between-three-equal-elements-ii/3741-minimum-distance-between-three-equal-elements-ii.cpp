class Solution {
public:
    int minimumDistance(vector<int>& nums) {
        int n = nums.size();
        int result = INT_MAX;
        unordered_map<int, vector<int>> mp;

        for(int k=0; k<n; k++){
            mp[nums[k]].push_back(k);

            if(mp[nums[k]].size() >= 3){
                vector<int> &vec = mp[nums[k]];

                int size = vec.size();
                int i = vec[size-3];
                result = min(result, 2*(k-i));
            }
        }
        return result == INT_MAX ? -1 : result;
    }
};