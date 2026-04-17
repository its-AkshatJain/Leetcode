class Solution {
public:
    int reverseNum(int n){
        int num = 0;
        while(n){
            int digit = n%10;
            num = num*10 + digit;
            n = n/10;
        }
        return num;
    }

    int minMirrorPairDistance(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int, int> mp; 
        int result = INT_MAX;

        for(int j=0; j<n; j++){
        
            if(mp.count(nums[j])){
                result = min(result, j - mp[nums[j]] );
            }
            int rev = reverseNum(nums[j]);
            mp[rev] = j;
        }

        return result == INT_MAX ? -1 : result;
    }
};