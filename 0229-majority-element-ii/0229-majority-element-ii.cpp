class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int n = nums.size();
        int cnt1 = 0, cnt2 = 0;
        int ele1 = INT_MIN;
        int ele2 = INT_MIN;
        
        for(int i=0; i<n; i++){
            if(cnt1 == 0 && ele2 != nums[i]){
                cnt1 = 1;
                ele1 = nums[i];
            }else if(cnt2 == 0 && ele1 != nums[i]){
                cnt2 = 1;
                ele2 = nums[i];
            }else if(ele1 == nums[i]) cnt1++;
            else if(ele2 == nums[i]) cnt2++;
            else{
                cnt1--;
                cnt2--;
            }
        }

        vector<int> res;
        cnt1 = 0, cnt2 = 0;
        for(int i=0; i<n; i++){
            if(nums[i] == ele1) cnt1++;
            if(nums[i] == ele2) cnt2++;
        }
        if(cnt1 > n/3) res.push_back(ele1);
        if(cnt2 > n/3) res.push_back(ele2);
        return res;
    }
};