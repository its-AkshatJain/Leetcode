class Solution {
    int getDigitSum(int val){
        int sum=0;
        while(val){
            sum += val%10;
            val /= 10;
        }
        return sum;
    }
public:
    int maximumSum(vector<int>& nums) {
        unordered_map<int,int> sum_maxval;
        int max_sum=-1;
        for(int ele: nums){
            int digit_sum = getDigitSum(ele);
            if(sum_maxval.count(digit_sum)){
                max_sum = max(max_sum, ele + sum_maxval[digit_sum]);
                if(sum_maxval[digit_sum]<ele)
                    sum_maxval[digit_sum]=ele;
            }else{
                sum_maxval[digit_sum] = ele;
            }
        }
        return max_sum;
    }
};