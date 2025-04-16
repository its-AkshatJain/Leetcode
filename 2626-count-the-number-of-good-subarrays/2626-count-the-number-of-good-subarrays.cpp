class Solution {
public:
    long long countGood(vector<int>& nums, int k) {
        long long n = nums.size();
        long long left = 0, right = 0;
        long long equalpairs = 0;
        long long goodSubarray = 0;
        unordered_map<long long, long long> freq;

        while(left < n){
            while(right<n && equalpairs<k){
                freq[nums[right]]++;
                if(freq[nums[right]]>=2){
                    equalpairs += freq[nums[right]]-1;
                }
                right++;
            }

            if(equalpairs>=k){
                goodSubarray += n - right + 1;
            }

            freq[nums[left]]--;
            if(freq[nums[left]]>0){
                equalpairs -= freq[nums[left]];
            }
            left++;
        }
        return goodSubarray;
    }
};