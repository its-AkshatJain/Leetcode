class Solution {
public:
    int findLHS(vector<int>& nums) {
        unordered_map<int, int> freq;

        for(int num: nums){
            freq[num]++;
        }

        int result = 0;
        for(int num: nums){
            int minNum = num;
            int maxNum = num+1;

            if(freq.count(maxNum)){
                result = max(result, freq[maxNum]+freq[minNum]);
            }
        }
        return result;
    }
};