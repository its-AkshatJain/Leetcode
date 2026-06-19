class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        int n = gain.size();
        int currentAltitude = 0;
        int result = currentAltitude;

        for(int i=0; i<n; i++){
            currentAltitude += gain[i];
            result = max(result, currentAltitude);
        }

        return result;
    }
};