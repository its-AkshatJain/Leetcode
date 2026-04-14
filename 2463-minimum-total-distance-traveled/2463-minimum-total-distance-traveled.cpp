class Solution {
    typedef long long ll;
    ll solve(int ri, int fi, vector<int>& robot, vector<int>& positions, vector<vector<ll>> &dp){
        if(ri >= robot.size()){
            return 0;
        }

        if(fi >= positions.size()){
            return 1e12;
        }

        if(dp[ri][fi] != -1){
            return dp[ri][fi];
        }

        ll take_current_factory = abs(robot[ri] - positions[fi]) + solve(ri+1, fi+1, robot, positions,dp); 
        ll skip = solve(ri, fi+1, robot, positions, dp); 

        return dp[ri][fi] = min(take_current_factory, skip);
    }
public:
    long long minimumTotalDistance(vector<int>& robot, vector<vector<int>>& factory) {
        sort(robot.begin(), robot.end());
        sort(factory.begin(), factory.end());
    
        vector<int> positions;
        for(int i=0; i<factory.size(); i++){
            int limit = factory[i][1];
            int pos = factory[i][0];

            for(int j=0; j<limit; j++){
                positions.push_back(pos);
            }
        }

        int m = robot.size();
        int n = positions.size();
        vector<vector<ll>> dp(m, vector<ll>(n, -1));

        return solve(0, 0, robot, positions, dp); 
    }
};