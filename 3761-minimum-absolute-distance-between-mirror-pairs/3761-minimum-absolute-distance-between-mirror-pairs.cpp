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

        for(int i=0; i<n; i++){
        
            if(mp.count(nums[i])){
                result = min(result, i - mp[nums[i]] );
            }
            int rev = reverseNum(nums[i]);
            mp[rev] = i;
        }

        return result == INT_MAX ? -1 : result;
    }
};