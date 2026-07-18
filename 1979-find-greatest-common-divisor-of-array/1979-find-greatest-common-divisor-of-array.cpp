class Solution {
public:
    int gcd(int a , int b){
        while(a != 0){
            int temp = a;
            a = b%a;
            b = temp;
        }
        return b;
    }
    int findGCD(vector<int>& nums) {
        int n = nums.size();
        int mini = nums[0];
        int maxi = nums[0];
        for(int i=1; i<n; i++){
            mini = min(mini, nums[i]);
            maxi = max(maxi, nums[i]);
        }

        return gcd(mini, maxi);
    }
};