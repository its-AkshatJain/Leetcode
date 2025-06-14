class Solution {
public:
    int minMaxDifference(int num) {
        string s = to_string(num);

        // for Maximum
        string maxS = s;
        char toReplaceMax = 0;
        for(char c: maxS){
            if(c != '9'){
                toReplaceMax = c;
                break;
            }
        }

        if(toReplaceMax){
            for(char &c: maxS){
                if(c == toReplaceMax){
                    c = '9';
                }
            }
        }
        
        int maxi = stoi(maxS);

        // for Minimum
        string minS = s;
        char toReplaceMin = 0;
        for(char c: minS){
            if(c != '0'){
                toReplaceMin = c;
                break;
            }
        }

        if(toReplaceMin){
            for(char &c: minS){
                if(c == toReplaceMin){
                    c = '0';
                }
            }
        }
        int mini = stoi(minS);

        return maxi-mini;
    }
};