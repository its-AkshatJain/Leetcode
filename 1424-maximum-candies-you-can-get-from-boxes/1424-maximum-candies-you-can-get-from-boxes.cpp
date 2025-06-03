class Solution {
public:
    int maxCandies(vector<int>& status, vector<int>& candies, vector<vector<int>>& keys, vector<vector<int>>& containedBoxes, vector<int>& initialBoxes) {
        int n = status.size();

        queue<int> q;
        for(int start: initialBoxes){
           q.push(start); 
        }
        unordered_set<int> closed;
        int total = 0;

        while(!q.empty()){
            int curr = q.front();
            q.pop();
            
            // If closed
            if(status[curr] == 0){
                closed.insert(curr);
                continue;
            }

            // if open, open other possible keys
            for(int open: keys[curr]){
                status[open] = 1;
                if(closed.count(open)){
                    q.push(open);
                    closed.erase(open);
                }
            }

            total += candies[curr];
            for(int nbr: containedBoxes[curr]){
                q.push(nbr);
            }
        }
        return total;
    }
};