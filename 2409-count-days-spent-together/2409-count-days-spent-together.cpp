class Solution {
public:
    int dayOfYear(string day, vector<int>& cumulativeMonthSum) {
        int month = stoi(day.substr(0, 2));
        int date = stoi(day.substr(3));

        return cumulativeMonthSum[month - 1] + date;
    }

    int countDaysTogether(string arriveAlice, string leaveAlice,
                          string arriveBob, string leaveBob) {
        vector<int> monthDays = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

        vector<int> cumulativeMonthSum(13, 0);
        cumulativeMonthSum[1] = 31;
        for (int i = 2; i <= 12; i++) {
            cumulativeMonthSum[i] = cumulativeMonthSum[i - 1] + monthDays[i - 1];
        }

        int arriveAliceDay = dayOfYear(arriveAlice, cumulativeMonthSum);
        int leaveAliceDay = dayOfYear(leaveAlice, cumulativeMonthSum);
        int arriveBobDay = dayOfYear(arriveBob, cumulativeMonthSum);
        int leaveBobDay = dayOfYear(leaveBob, cumulativeMonthSum);

        int overlapDays = min(leaveAliceDay, leaveBobDay) - max(arriveAliceDay, arriveBobDay) + 1;

        return overlapDays > 0 ? overlapDays : 0;
    }
};