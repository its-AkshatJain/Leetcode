class Solution {
public:
    int minElement(vector<int>& nums) {
        int n = nums.size();
        int result = INT_MAX;
        
        for(int &num: nums){
            int sum = 0;
            while(num){
                int digit = num%10;
                sum += digit;
                num = num/10;
            }
            result = min(result, sum);
        }

        return result;
    }
};