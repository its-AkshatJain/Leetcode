class Solution {
public:
    bool findSafeWalk(vector<vector<int>>& grid, int health) {
        int m = grid.size();
        int n = grid[0].size();
        vector<pair<int, int>> directions{{1, 0}, {-1, 0}, {0, -1}, {0, 1}};

        vector<vector<int>> dist(m, vector<int>(n, INT_MAX));
        dist[0][0] = grid[0][0];
        deque<pair<int, int>> dq;
        dq.push_front({0, 0});

        while(!dq.empty()){
            int curr_x = dq.front().first;
            int curr_y = dq.front().second;
            dq.pop_front();

            for(auto& [dx, dy]: directions){
                int new_x = curr_x + dx;
                int new_y = curr_y + dy;

                if(new_x < 0 || new_x >= m || new_y < 0 || new_y >=n){
                    continue;
                }

                int cost = grid[new_x][new_y];

                if(dist[curr_x][curr_y] + cost < dist[new_x][new_y]){
                    dist[new_x][new_y] = dist[curr_x][curr_y] + cost;

                    if(cost == 0){
                        dq.push_front({new_x, new_y});
                    }else{
                        dq.push_back({new_x, new_y});
                    }
                }
            }     
        }
        return dist[m-1][n-1] < health;
    }
};