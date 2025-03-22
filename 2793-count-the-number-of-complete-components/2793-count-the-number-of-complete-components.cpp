class Solution {
    void dfs(int curr, int& nodes, int& edges, vector<vector<int>>& adj, vector<bool>& visited){
        nodes++;
        visited[curr] = true;
        for(auto nbr: adj[curr]){
            edges++;
            if(!visited[nbr]){
                dfs(nbr, nodes, edges, adj, visited);
            }
        }
    }
public:
    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj(n);
        for(auto edge: edges){
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }

        int complete_comp = 0;
        vector<bool> visited(n,false);
        for(int i=0; i<n; i++){
            if(!visited[i]){
                int nodes = 0;
                int edges = 0;
                dfs(i, nodes, edges, adj, visited);

                if(edges == nodes*(nodes-1)){
                    complete_comp++;
                }
            }
        }
        return complete_comp;
    }
};