class Solution {
public:
    int countDays(int days, vector<vector<int>>& meetings) {
        vector<pair<int, int>> time;
        for(auto meeting: meetings){
            time.push_back(make_pair(meeting[0],1));
            time.push_back(make_pair(meeting[1]+1,0));
        }
        sort(time.begin(), time.end());

        int overlap = 0;
        int count = time[0].first - 1;
        for(int i=0; i<time.size()-1; i++){
            if(time[i].second == 0) overlap--;
            else          overlap++;

            if(overlap == 0){
                count += time[i+1].first - time[i].first;
            }
        }
        count += days - time.back().first + 1;
        return count;
    }
};