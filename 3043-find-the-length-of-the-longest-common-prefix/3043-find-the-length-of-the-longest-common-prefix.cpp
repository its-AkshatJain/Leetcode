class Solution {
public:
    int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2) {
        unordered_set<int> st;
        int result = 0;

        for(int num: arr1){
            while(num>0 && !st.count(num)){
                st.insert(num);
                num = num/10;
            }
        }

        for(int num: arr2){
            while(num>0 && !st.count(num)){
                num = num/10;
            }
            
            if(num>0){
                result = max(result, static_cast<int>(log10(num)+1));
            }

        }

        return result;
    }
};