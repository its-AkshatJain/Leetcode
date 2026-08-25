class Solution {
public:
    int missingMultiple(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_set<int> st;
        for(int num: nums){
            st.insert(num);
        }

        for(int i=1; i<=n+1; i++){
            int multiple = k*i;
            if(st.find(multiple) == st.end()){
                return multiple;
            }
        }

        return -1;
    }
};