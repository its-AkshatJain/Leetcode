class Solution {
public:
    int maxDistance(vector<int>& nums1, vector<int>& nums2) {
        int m = nums1.size();
        int n = nums2.size();
        int maxDist = 0;
        int i = 0, j=0;

        while(i<m && j<n){
            if(nums1[i] <= nums2[j]){
                maxDist = max(maxDist, j-i);
                j++;
            }else{
                i++;
            }
        }
        return maxDist;
    }
};