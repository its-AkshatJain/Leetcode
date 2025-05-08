class Solution {
    typedef tuple<int, int, int, int> tp; // (curr_time, i, j, move_count)
public:
    int minTimeToReach(vector<vector<int>>& moveTime) {
        int n = moveTime.size();
        int m = moveTime[0].size();
        vector<vector<int>> res(n, vector<int>(m, INT_MAX));

        priority_queue<tp, vector<tp>, greater<tp>> pq;
        pq.push({0,0,0,0});
        res[0][0] = 0;
        int dir[] = {-1,0,1,0,-1};
        while(!pq.empty()){
            auto [currtime,i,j,moveCount] = pq.top();
            pq.pop();

            if(currtime > res[i][j]) continue;

            if(i==n-1 && j == m-1){
                return currtime;
            }

            for(int k=0; k<4; k++){
                int new_i = i + dir[k];
                int new_j = j + dir[k+1];
                
                if(new_i>=0 && new_i<n && new_j>=0 && new_j<m){
                    int move_cost = (moveCount % 2 == 0)? 1 : 2;
                    int wait = max(0, moveTime[new_i][new_j]-currtime);
                    int arrtime = currtime + wait + move_cost;
                    
                    if(res[new_i][new_j] > arrtime){
                        res[new_i][new_j] = arrtime;
                        pq.push({arrtime,new_i, new_j, moveCount+1});
                    }
                }
            }
        }
        return res[n-1][m-1];
    }
};