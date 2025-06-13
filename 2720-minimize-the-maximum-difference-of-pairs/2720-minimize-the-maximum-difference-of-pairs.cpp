class Solution {
public:
    bool isPossible(int val, vector<int>& nums, int p){
        int count = 0;
        int i=1;
        while(i<nums.size()){
            if(nums[i] - nums[i-1] <= val){
                count++;
                i+=2;
            }else{
                i++;
            }
        }

        return count >= p;
    }
    int minimizeMax(vector<int>& nums, int p) {
        sort(nums.begin(), nums.end());
        int low = 0, high = nums.back(), mid;
        int result = INT_MIN;

        while(low <= high){
            mid = low + (high - low)/2;
            if(isPossible(mid, nums, p)){
                result = mid;
                high = mid - 1;
            }else{
                low = mid + 1;
            }
        }

        return result;
    }
};