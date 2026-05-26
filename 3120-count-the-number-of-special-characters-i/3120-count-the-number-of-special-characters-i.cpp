class Solution {
public:
    int numberOfSpecialChars(string word) {
        unordered_set<int> upper, lower;
        int count = 0;

        for(char& ch: word){
            if(islower(ch)){
                lower.insert(ch);
            }else{
                upper.insert(ch);
            }
        }

        for(char ch='a'; ch<='z'; ch++){
            if(upper.count(toupper(ch)) && lower.count(ch)){
                count++;
            }
        }

        return count;
    }
};