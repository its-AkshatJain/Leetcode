class Solution {
public:
    vector<int> lexicographicallySmallestArray(vector<int>& nums, int limit) {
        int n = nums.size();

        vector<pair<int, int>> v;

        // value, original index
        for (int i = 0; i < n; i++) {
            v.push_back({nums[i], i});
        }

        // Sort by value
        sort(v.begin(), v.end());

        int left = 0;

        while (left < n) {

            int right = left;

            // Find the current connected component
            while (right + 1 < n &&
                   v[right + 1].first - v[right].first <= limit) {
                right++;
            }

            // Collect original indices
            vector<int> positions;

            for (int i = left; i <= right; i++) {
                positions.push_back(v[i].second);
            }

            // Smallest positions first
            sort(positions.begin(), positions.end());

            // Values v[left...right] are already sorted
            for (int i = 0; i < positions.size(); i++) {
                nums[positions[i]] = v[left + i].first;
            }

            // Move to next component
            left = right + 1;
        }

        return nums;
    }
};