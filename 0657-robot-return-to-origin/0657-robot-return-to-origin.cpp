class Solution {
public:
    bool judgeCircle(string moves) {
        int upCount = 0;
        int rightCount = 0;

        for(char &move: moves){
            if(move == 'U'){
                upCount++;
            }else if(move == 'D'){
                upCount--;
            }else if(move == 'R'){
                rightCount++;
            }else{
                rightCount--;
            }
        }

        return upCount==0 && rightCount==0;
    }
};