class Solution {
public:
    int minMoves(vector<int>& nums, int limit) {
        int n = nums.size();
        vector<int> diff(2*limit+2, 0);

        for(int i=0; i<n/2; i++){
            int a = nums[i];
            int b = nums[n-i-1];
            int sum = a+b;

            int low = min(a,b) + 1;
            int high = max(a,b) + limit;

            // For 1 moves
            diff[low] -= 1;
            diff[high+1] += 1;

            // For 0 moves
            diff[sum] -= 1;
            diff[sum+1] += 1;
        }

        int pairs = n/2;
        int curr = 2 * pairs; //as initially assumed 2 moves
        int ans = INT_MAX;

        for(int s=2; s<=2*limit; s++){
            curr += diff[s];
            ans = min(ans, curr);
        }

        return ans;
    }
};