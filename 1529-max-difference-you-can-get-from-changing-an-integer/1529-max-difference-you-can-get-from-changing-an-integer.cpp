class Solution {
public:
    int maxDiff(int num) {
        string s = to_string(num);
        int n = s.size();
        // Find a
        string a = s;
        char eleToReplaceA = '\0';
        for(int i=0; i<n; i++){
            if(a[i] != '9'){
                eleToReplaceA = a[i];
                break;
            } 
        }

        if(eleToReplaceA != '\0'){
            for(int i=0; i<n; i++){
                if(a[i] == eleToReplaceA) a[i] = '9';
            }
        }

        // Find b
        string b = s;
        char eleToReplaceB = '\0';
        bool toZero = false;
        for(int i=0; i<n; i++){
            if(b[i] != '1' && b[i]!='0'){
                eleToReplaceB = b[i];
                toZero = (i!=0);
                break;
            } 
        }
        if(eleToReplaceB != '\0'){
            for(int i=0; i<n; i++){
                if(b[i] == eleToReplaceB) b[i] = toZero? '0': '1';
            }
        }
        int diff = stoi(a) - stoi(b);

        return diff;
    }
};