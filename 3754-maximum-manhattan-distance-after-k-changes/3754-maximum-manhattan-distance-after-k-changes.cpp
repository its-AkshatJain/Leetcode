class Solution {
public:
    int maxDistance(string s, int k) {
        int maxD = 0;

        int north = 0;
        int south = 0;
        int east = 0;
        int west = 0;

        for(int i=0; i<s.length(); i++){
            if(s[i] == 'N') north++;
            else if(s[i] == 'S') south++;
            else if(s[i] == 'E') east++;
            else if(s[i] == 'W') west++;
            
            int currD = abs(north - south) + abs(east - west);
            int steps = i+1;
            int wasted = steps - currD;

            int extra = 0;
            if(wasted != 0){
                extra = min(2*k, wasted);
            }

            int finalCurrD = currD + extra;
            maxD = max(maxD, finalCurrD);
        }
        return maxD;
    }
};