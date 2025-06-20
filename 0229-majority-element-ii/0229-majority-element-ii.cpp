class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int,int> freq;
        for(int num: nums){
            freq[num]++;
        }
        
        vector<int> res;
        for(auto [ele, count]: freq){
            if(count>floor(n/3)) res.push_back(ele);
        }
        return res;
    }
};