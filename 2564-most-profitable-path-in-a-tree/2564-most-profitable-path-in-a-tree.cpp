class Solution {
    bool findBobPath(vector<vector<int>> &adj, int bob, int parent, vector<int> &bob_path, vector<int> &curr_path){
        if(bob == 0){
            bob_path = curr_path;
            return true;
        }
        // Traverse all nbr
        curr_path.push_back(bob);
        for(int nbr: adj[bob]){
            if(nbr!=parent && findBobPath(adj, nbr, bob, bob_path, curr_path)){
                return true;
            }
        }
        curr_path.pop_back();
        return false;
    }
    int findMaxIncomeAlice(vector<vector<int>> &adj, int alice, int parent,vector<int> &amount){
        int max_income = INT_MIN;
        for(int nbr: adj[alice]){
            if(nbr!=parent){
                int income = findMaxIncomeAlice(adj, nbr, alice, amount);
                if(income + amount[alice] > max_income){
                    max_income = income + amount[alice];
                }
            }
        }
        return max_income==INT_MIN? amount[alice]:max_income;
    }
public:
    int mostProfitablePath(vector<vector<int>>& edges, int bob, vector<int>& amount) {
        int n = amount.size();
        vector<vector<int>> adj(n);
        // Step 1: Find Adj List
        for(auto edge: edges){
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }

        // Step 2: Find the bob to root path
        vector<int> bob_path, curr_path;
        findBobPath(adj, bob, -1, bob_path, curr_path);

        // Step 3: Make amount 0 of half bob_path
        int size = bob_path.size();
        int i;
        for(i=0; i<size/2; i++){
            amount[bob_path[i]] = 0;
        }
        if(size&1) amount[bob_path[i]] = 0;
        else       amount[bob_path[i]] /=2; //Half contribution for all meeting point

        // DFS for max sum
        return findMaxIncomeAlice(adj, 0, -1, amount);
    }
};