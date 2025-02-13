class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        int operation = 0;
        priority_queue<long long, vector<long long>, greater<long long>> minHeap(nums.begin(), nums.end());

        while(minHeap.size() > 1 && minHeap.top() < k){
            long long min1 =minHeap.top();
            minHeap.pop();
            long long min2 =minHeap.top();
            minHeap.pop();

            long long newEle = min1 * 2 + min2;
            minHeap.push(newEle);
            operation++;
        }
        return operation;
    }
};