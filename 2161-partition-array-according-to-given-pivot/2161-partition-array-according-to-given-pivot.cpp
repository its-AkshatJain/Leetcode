class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        int n = nums.size();
        vector<int> result(n, 0);
        int equalCount = 0;
        int start = 0;
        int end = n - 1;

        for (int i = 0; i < n; i++) {
            if (nums[i] < pivot) {
                result[start++] = nums[i];
            } else if (nums[i] == pivot) {
                equalCount++;
            } else {
                result[end--] = nums[i];
            }
        }

        while (equalCount--) {
            result[start++] = pivot;
        }

        reverse(result.begin() + end + 1, result.end());

        return result;
    }
};