class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int, int> freq;
        for(int i=0; i<n; i++){
            freq[nums[i]]++;
        }
        for(auto& [num, count]: freq){
            if(count > (n/2)){
                return num;
            }
        }

        return -1;
    }
};