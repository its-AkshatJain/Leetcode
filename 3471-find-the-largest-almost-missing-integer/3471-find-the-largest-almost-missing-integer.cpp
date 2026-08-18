class Solution {
public:
    int largestInteger(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int, int> freq;
        int maxNum = INT_MIN;
        int maxSingleNum = INT_MIN;

        for(int num: nums){
            freq[num]++;
            maxNum = max(maxNum, num);
        }

        for(auto &[num, count]: freq){
            if(count == 1){
                maxSingleNum = max(maxSingleNum, num);
            }
        }

        if(k == 1){
            return maxSingleNum == INT_MIN ? -1 : maxSingleNum;
        }

        if(k == n){
            return maxNum;
        }

        int result = 0;
        if(freq[nums[0]] == 1 && freq[nums[n-1]] == 1){
            result = max(nums[0], nums[n-1]);
        }else if(freq[nums[0]] > 1 && freq[nums[n-1]] == 1){
            result = nums[n-1];
        }else if(freq[nums[0]] == 1 && freq[nums[n-1]] > 1){
            result = nums[0];
        }else{
            result = -1;
        }

        return result;
    }
};