#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> gcdValues(vector<int>& nums, vector<long long>& queries) {
        int mx = *max_element(nums.begin(), nums.end());

        // freq[i] = frequency of number i
        vector<long long> cnt(mx + 1, 0);
        for (int x : nums)
            cnt[x]++;

        // cnt[i] = numbers divisible by i
        for (int i = 1; i <= mx; i++) {
            for (int j = i * 2; j <= mx; j += i)
                cnt[i] += cnt[j];
        }

        // cnt[i] = pairs divisible by i
        for (int i = 1; i <= mx; i++)
            cnt[i] = cnt[i] * (cnt[i] - 1) / 2;

        // Inclusion-Exclusion:
        // cnt[i] = pairs whose GCD is exactly i
        for (int i = mx; i >= 1; i--) {
            for (int j = i * 2; j <= mx; j += i)
                cnt[i] -= cnt[j];
        }

        // Prefix sum:
        // cnt[i] = pairs having GCD <= i
        for (int i = 1; i <= mx; i++)
            cnt[i] += cnt[i - 1];

        vector<int> ans;

        for (long long q : queries) {
            long long target = q + 1; // q is 0-based index
            int gcdValue = lower_bound(cnt.begin(), cnt.end(), target) - cnt.begin();
            ans.push_back(gcdValue);
        }

        return ans;
    }
};