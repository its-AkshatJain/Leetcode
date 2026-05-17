class Solution {
public:
    bool solve(vector<int>& arr, int i, int n){
        if(i<0 || i>=n || arr[i]<0){
            return false;
        }

        if(arr[i] == 0){
            return true;
        }

        arr[i] *= -1;

        int left = solve(arr, i - arr[i], n);
        int right = solve(arr, i + arr[i], n);

        return left || right;
    }
    bool canReach(vector<int>& arr, int start) {
        int n = arr.size();

        return solve(arr, start, n);
    }
};