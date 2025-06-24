class Solution {
public:
    vector<int> findKDistantIndices(vector<int>& nums, int key, int k) {
        int n = nums.size();
        vector<bool> isKDist(n,false);
        vector<int> result;

        for(int i=0; i<n; i++){
            if(nums[i] == key){
                int start = max(0, i-k);
                int end = min(n-1, i+k);

                for(int j=start; j<=end; j++){
                    isKDist[j] = true;
                }
            }
        }

        for(int i=0; i<n; i++){
            if(isKDist[i]) result.push_back(i);
        }
        return result;
    }
};