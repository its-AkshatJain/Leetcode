class Solution {
public:
    int earliestFinishTime(vector<int>& landStartTime, vector<int>& landDuration, vector<int>& waterStartTime, vector<int>& waterDuration) {
        int n = landStartTime.size();
        int m = waterStartTime.size();

        int result = INT_MAX;

        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){

                // Land -> water
                int landFinishTime = landStartTime[i] + landDuration[i];

                int waterBeginTime = max(landFinishTime, waterStartTime[j]);
                
                result = min(result, waterBeginTime + waterDuration[j]);

                // Water -> Land
                int waterFinishTime = waterStartTime[j] + waterDuration[j];

                int landBeginTime = max(waterFinishTime, landStartTime[i]);
                
                result = min(result, landBeginTime + landDuration[i]);
            }
        }

        return result;
    }
};