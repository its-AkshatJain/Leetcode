class Solution {
public:
    vector<int> lexicographicallySmallestArray(vector<int>& nums, int limit) {
        int n = nums.size();

        // Step 1 : Find location of each number and sort the array
        vector<pair<int, int>> copy;
        for(int i=0; i<n; i++){
            copy.push_back({nums[i], i});
        }
        sort(copy.begin(), copy.end());

        // Step 2: Find groups and place values
        int left = 0, right = 1;
        while(right<n){
            vector<int> pos = {copy[left].second};

            while(right<n && abs(copy[right].first - copy[right-1].first <= limit)){
                pos.push_back(copy[right].second);
                right++;
            }
            // Order Indices
            sort(pos.begin(), pos.end());
            for(int i=0; i<right - left; i++){
                nums[pos[i]] = copy[left+i].first;
            }

            left = right;
            right++;
        }
        return nums;
    }
};