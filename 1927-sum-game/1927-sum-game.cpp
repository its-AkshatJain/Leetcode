class Solution {
public:
    bool sumGame(string num) {
        int n = num.size();
        int leftKnownSum = 0;
        int rightKnownSum = 0;

        int leftQnMarkCount = 0;
        int rightQnMarkCount = 0;

        for (int i = 0; i < n; i++) {
            if (num[i] == '?') {
                if (i < n / 2) {
                    leftQnMarkCount++;
                } else {
                    rightQnMarkCount++;
                }
            }else{
                if (i < n / 2) {
                    leftKnownSum += num[i] - '0';
                } else {
                    rightKnownSum += num[i] - '0';
                }
            }
        }

        int totalQnMark = leftQnMarkCount + rightQnMarkCount;
        if(totalQnMark % 2 == 1){ // ODD Alice wins
            return true;
        }

        int left = 2*leftKnownSum + 9*leftQnMarkCount;
        int right = 2*rightKnownSum + 9*rightQnMarkCount;

        if(left == right){
            return false;
        }

        return true;
    }
};