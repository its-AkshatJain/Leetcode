class Solution {
public:
    void dfs(int node, vector<bool>& visited,
             unordered_map<int, vector<vector<int>>>& adj, int& ans) {
        visited[node] = true;

        for (auto& vec : adj[node]) {
            int ngbr = vec[0];
            int dist = vec[1];

            ans = min(ans, dist);

            if (!visited[ngbr]) {
                dfs(ngbr, visited, adj, ans);
            }
        }
    }

    int minScore(int n, vector<vector<int>>& roads) {
        unordered_map<int, vector<vector<int>>> adj;
        vector<bool> visited(n+1, false);
        int ans = INT_MAX;

        for (auto& road : roads) {
            int u = road[0];
            int v = road[1];
            int distance = road[2];

            adj[u].push_back({v, distance});
            adj[v].push_back({u, distance});
        }

        dfs(1, visited, adj, ans);

        return ans;
    }
};