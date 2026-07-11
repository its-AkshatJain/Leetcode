class Solution {
public:
    void dfs(int curr, int& nodes, int& degree, vector<vector<int>>& adj,
             vector<bool>& visited) {
        visited[curr] = true;
        nodes++;

        degree += adj[curr].size();
        for (auto& nbr : adj[curr]) {
            if (!visited[nbr]) {
                dfs(nbr, nodes, degree, adj, visited);
            }
        }
    }
    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj(n);

        for (auto& edge : edges) {
            int u = edge[0];
            int v = edge[1];

            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        int complete_comp = 0;
        vector<bool> visited(n, false);

        for (int i = 0; i < n; i++) {
            if (!visited[i]) {
                int nodes = 0;
                int degree = 0;

                dfs(i, nodes, degree, adj, visited);
                int edges = degree / 2;
                if (edges == (nodes * (nodes - 1)) / 2) {
                    complete_comp++;
                }
            }
        }

        return complete_comp;
    }
};