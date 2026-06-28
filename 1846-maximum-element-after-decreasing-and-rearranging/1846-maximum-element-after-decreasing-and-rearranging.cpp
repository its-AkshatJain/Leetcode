class Solution {
public:
    int maximumElementAfterDecrementingAndRearranging(vector<int>& arr) {
        int n = arr.size();
        int maxElement = 0;
        sort(arr.begin(), arr.end());

        for (int i = 0; i < n; i++) {
            if (i == 0) {
                arr[i] = 1;
            } else if (abs(arr[i] - arr[i - 1]) > 1) {
                arr[i] = arr[i - 1] + 1;
            }

            maxElement = max(maxElement, arr[i]);
        }

        return maxElement;
    }
};