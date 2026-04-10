class Solution {
public:
    int minimumDistance(vector<int>& nums) {
        int n = nums.size();
        int minDist = INT_MAX;
        unordered_map<int, vector<int>> mp;

        for(int i=0; i<n; i++){
            mp[nums[i]].push_back(i);
        }
        
        for(auto &p: mp){
            auto &v = p.second;
            int m = v.size();

            if(m < 3) continue;

            for(int i=0; i<=m-3; i++){
                int k = i+2;
                int dist = 2*(v[k]-v[i]);
                minDist = min(minDist, dist);
            }
        }

        return minDist == INT_MAX ? -1 : minDist;
    }
};