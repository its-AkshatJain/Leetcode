class Solution {
    pair<int,int> getCoord(int num, int n){
        int rTop = (num-1)/n;
        int rBottom = (n-1) - rTop;

        int col = (num-1)%n; 
        if((n%2==1 && rBottom%2==1) || (n%2==0 && rBottom%2==0)){
            col = (n-1) - col;
        }

        return {rBottom, col};
    }
public:
    int snakesAndLadders(vector<vector<int>>& board) {
        int n = board.size();
        int steps = 0;

        queue<int> q;
        q.push(1);
        vector<vector<bool>> visited(n, vector<bool>(n, false));
        visited[n-1][0] = true;

        while(!q.empty()){
            int size = q.size();

            while(size--){
                int x = q.front();
                q.pop();

                if(x == n*n){
                    return steps;
                }

                for(int k=1; k<=6; k++){
                    int val = x+k;

                    if(val > n*n){
                        break;
                    }

                    pair<int,int> coord = getCoord(val,n);
                    int r = coord.first;
                    int c = coord.second;

                    if(visited[r][c]) continue;

                    visited[r][c] = true;

                    if(board[r][c] == -1){
                        q.push(val);
                    }else{
                        q.push(board[r][c]);
                    }
                }
            }
            steps++;
        }
        return -1;
    }
};