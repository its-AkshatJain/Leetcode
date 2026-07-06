class Solution {
public:
    int removeCoveredIntervals(vector<vector<int>>& intervals) {
        int n = intervals.size();
        int covered = 0;

        for (int i = 0; i < n; i++) {
            int a = intervals[i][0];
            int b = intervals[i][1];

            for (int j = 0; j < n; j++) {
                if (j == i) {
                    continue;
                }
                int c = intervals[j][0];
                int d = intervals[j][1];

                if (a >= c && b <= d) {
                    covered++;
                    break;
                }
            }
        }

        return n - covered;
    }
};