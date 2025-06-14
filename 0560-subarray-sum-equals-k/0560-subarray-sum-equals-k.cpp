class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int,int> prefixSumCount;
        prefixSumCount[0] = 1;  // this will also handle prefixSum == k case

        int prefixSum = 0;
        int count = 0;

        for(int num: nums){
            prefixSum += num;

            if(prefixSumCount.count(prefixSum - k)){
                count += prefixSumCount[prefixSum - k];
            }

            prefixSumCount[prefixSum]++;
        }
        return count;
    }
};