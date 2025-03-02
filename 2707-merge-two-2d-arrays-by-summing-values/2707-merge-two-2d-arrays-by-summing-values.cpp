class Solution {
public:
    vector<vector<int>> mergeArrays(vector<vector<int>>& nums1, vector<vector<int>>& nums2) {
        vector<vector<int>> ans;
        int n = nums1.size();
        int m = nums2.size();
        int p1 = 0;
        int p2 = 0; 

        while(p1<n && p2<m){
            if(nums1[p1][0] == nums2[p2][0]){
                ans.push_back(nums1[p1]);
                ans.back()[1] += nums2[p2][1];
                p1++;
                p2++;
            }else if(nums1[p1][0] < nums2[p2][0]){
                ans.push_back(nums1[p1]);
                p1++;
            }else if(nums1[p1][0] > nums2[p2][0]){
                ans.push_back(nums2[p2]);
                p2++;
            }
        }
        // Fill leftover from num1
        while(p1<n){
            ans.push_back(nums1[p1]);
            p1++;
        }
        // Fill leftover from num2
        while(p2<m){
            ans.push_back(nums2[p2]);
            p2++;
        }
        return ans;
    }
};