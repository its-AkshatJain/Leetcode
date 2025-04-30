class Solution {
    bool evenDigits(int num){
        int count = 0;
        while(num){
            count++;
            num /=10;
        }
        if(count%2 == 0) return true;
        return false;
    }
public:
    int findNumbers(vector<int>& nums) {
        int count=0;
        for(int num: nums){
            if(evenDigits(num)){
                count++;
            }
        }
        return count;
    }
};