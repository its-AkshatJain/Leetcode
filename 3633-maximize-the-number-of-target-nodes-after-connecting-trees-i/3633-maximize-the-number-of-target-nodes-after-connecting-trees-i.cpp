class Solution {
    #define pii pair<int,int>
public:
    int BFS(int start, vector<vector<int>> &adj, int k){
        queue<pii> q;  //Node, parent
        q.push({start,-1});
        int count = 0;

        while(!q.empty() && k>=0){
            int size = q.size();
            count += size;

            for(int i=0; i<size; i++){
                pii curr = q.front();
                q.pop();

                int node = curr.first;
                int parent = curr.second;
                for(int nbr: adj[node]){
                    if(nbr != parent){
                        q.push({nbr, node});
                    }
                }
            }
            k--;
        }
        return count;
    }
    vector<int> maxTargetNodes(vector<vector<int>>& edges1, vector<vector<int>>& edges2, int k) {
        int n = edges1.size()+1;
        int m = edges2.size()+1;

        vector<vector<int>> adj1(n), adj2(m);

        for(auto edge: edges1){
            adj1[edge[0]].push_back(edge[1]);
            adj1[edge[1]].push_back(edge[0]);
        }

        for(auto edge: edges2){
            adj2[edge[0]].push_back(edge[1]);
            adj2[edge[1]].push_back(edge[0]);
        }

        // find best node in 2nd tree
        int best = 0;
        for(int i=0; i<m; i++){
            int connections = BFS(i, adj2, k-1);
            best = max(best, connections);
        }

        vector<int> res(n);
        for(int i=0; i<n; i++){
            int connections = BFS(i, adj1, k);
            res[i] = connections + best;
        }
        return res;
    }
};