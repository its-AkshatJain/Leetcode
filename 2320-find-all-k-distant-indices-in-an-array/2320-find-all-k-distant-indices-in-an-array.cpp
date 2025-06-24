class Solution {
public:
    vector<int> findKDistantIndices(vector<int>& nums, int key, int k) {
        int n = nums.size();
        vector<int> keyIndex;
        vector<int> result;

        for(int i=0; i<n; i++){
            if(nums[i] == key){
                keyIndex.push_back(i);
            }
        }

        for(int i=0; i<n; i++){
            for(int j=0; j<keyIndex.size(); j++){
                if(abs(i-keyIndex[j]) <= k){
                    result.push_back(i);
                    break;
                }
            }
        }
        return result;
    }
};