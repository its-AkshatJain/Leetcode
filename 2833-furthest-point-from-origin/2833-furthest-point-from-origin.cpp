class Solution {
public:
    int furthestDistanceFromOrigin(string moves) {
        int countL = 0;
        int countR = 0;
        int count_ = 0;

        for(char ch: moves){
            if(ch == 'L') countL++;
            else if(ch == 'R') countR++;
            else count_++;
        }

        return abs(countL - countR) + count_;
    }
};