class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int, int> freq;
        for(int i=0; i<n; i++){
            freq[nums[i]]++;
        }
        for(auto& pair: freq){
            if(pair.second > (n/2)){
                return pair.first;
            }
        }

        return -1;
    }
};