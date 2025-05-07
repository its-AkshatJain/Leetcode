class Solution {
public:
    typedef pair<int, pair<int,int>> pp;
    int minTimeToReach(vector<vector<int>>& moveTime) {
        int n = moveTime.size();
        int m = moveTime[0].size();
        vector<vector<int>> res(n, vector<int>(m, INT_MAX));

        int dir[] = {-1,0,1,0,-1};
        priority_queue<pp, vector<pp>, greater<pp>> pq; //minHeap //time,i,j

        res[0][0] = 0;
        pq.push({0,{0,0}}); 

        while(!pq.empty()){
            int currtime = pq.top().first;
            int i = pq.top().second.first;
            int j = pq.top().second.second;
            pq.pop();
            if (currtime > res[i][j]) continue;
            if(i==n-1 && j==m-1){
                return currtime;
            }

            for(int k=0; k<4; k++){
                int new_i = i+dir[k];
                int new_j = j+dir[k+1];

                if(new_i>=0 && new_i<n && new_j>=0 && new_j<m){
                    int wait = max(moveTime[new_i][new_j] - currtime, 0);
                    int arrTime = currtime + wait + 1;
                    
                    if(res[new_i][new_j] > arrTime){
                        res[new_i][new_j] = arrTime;
                        pq.push({arrTime, {new_i,new_j}});
                    }
                }
            }
        }
        return res[n-1][m-1];
    }
};