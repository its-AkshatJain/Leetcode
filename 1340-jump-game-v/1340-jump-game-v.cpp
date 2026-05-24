class Solution {
public:
    int n;
    vector<int> t;
    int solve(vector<int>& arr, int i, int d){
        if(t[i] != -1){
            return t[i];
        }
        
        int result = 1;

        // Left
        for(int j = i-1; j>=(max(0, i-d)); j--){
            if(arr[j] >= arr[i]) break;
            result = max(result, 1+solve(arr, j, d));
        }

        // Right
        for(int j = i+1; j<=min(n-1, i+d); j++){
            if(arr[j] >= arr[i]) break;
            result = max(result, 1+solve(arr, j, d));
        }

        return t[i] = result;
    }

    int maxJumps(vector<int>& arr, int d) {
        n = arr.size();
        int result = 1;
        t.resize(n+1, -1);

        for(int i=0; i<n; i++){
            result = max(result, solve(arr, i, d));
        }

        return result;
    }
};