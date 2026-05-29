class Solution {
public:
    int minElement(vector<int>& nums) {
        int n = nums.size();
        int result = INT_MAX;
        
        for(int &num: nums){
            int sum = 0;
            string stringNum = to_string(num);
            for(char &ch: stringNum) {
                sum += ch-'0';
            }
            result = min(result, sum);
        }

        return result;
    }
};