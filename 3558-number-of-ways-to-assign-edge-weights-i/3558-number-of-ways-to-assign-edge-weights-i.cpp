class Solution {
public:
    long long M = 1e9 + 7;
    long long power(long long base, long long exponent) {
        if (exponent == 0) {
            return 1;
        }
        long long half = power(base, exponent / 2);
        int result = (half * half) % M;
        if (exponent % 2 == 1) {
            result = (result * base) % M;
        }
        return result;
    }
    int findMaxDepth(unordered_map<int, vector<int>>& adj, int node,
                     int parent) {
        int depth = 0;
        for (auto& neighbour : adj[node]) {
            if (neighbour == parent)
                continue;
            depth = max(depth, findMaxDepth(adj, neighbour, node) + 1);
        }

        return depth;
    }
    int assignEdgeWeights(vector<vector<int>>& edges) {
        unordered_map<int, vector<int>> adj;

        for (auto& edge : edges) {
            int u = edge[0];
            int v = edge[1];

            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        int d = findMaxDepth(adj, 1, -1);

        return (int)power(2, d - 1);
    }
};
