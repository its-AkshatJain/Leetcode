#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> parent;

    // Find with path compression
    int find(int x) {
        if (parent[x] != x)
            parent[x] = find(parent[x]);
        return parent[x];
    }

    // Union
    void unite(int x, int y) {
        parent[find(x)] = find(y);
    }

    int minimumHammingDistance(vector<int>& source, vector<int>& target, vector<vector<int>>& allowedSwaps) {
        int n = source.size();
        parent.resize(n);

        // Initialize DSU
        for (int i = 0; i < n; i++)
            parent[i] = i;

        // Step 1: Build connected components
        for (auto &p : allowedSwaps) {
            unite(p[0], p[1]);
        }

        // Step 2: Group indices by root
        unordered_map<int, vector<int>> groups;
        for (int i = 0; i < n; i++) {
            int root = find(i);
            groups[root].push_back(i);
        }

        int result = 0;

        // Step 3: Process each component
        for (auto &g : groups) {
            unordered_map<int, int> freq;

            // Count values from source
            for (int idx : g.second) {
                freq[source[idx]]++;
            }

            // Try matching target
            for (int idx : g.second) {
                if (freq[target[idx]] > 0) {
                    freq[target[idx]]--;
                } else {
                    result++;
                }
            }
        }

        return result;
    }
};