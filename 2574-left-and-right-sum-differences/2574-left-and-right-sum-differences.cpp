class Solution {
public:
    vector<int> leftRightDifference(vector<int>& nums) {
        int n = nums.size();
        vector<int> answer(n, 0);

        int leftSum = 0;
        for(int i=1; i<n; i++){
            leftSum += nums[i-1];
            answer[i] += leftSum;
        }

        int rightSum = 0;
        for(int i=n-2; i>=0; i--){
            rightSum += nums[i+1];
            answer[i] = abs(answer[i] - rightSum);
        }

        return answer;
    }
};