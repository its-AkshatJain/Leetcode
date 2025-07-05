class Solution {
public:
    int findLucky(vector<int>& arr) {
        int result = -1;
        unordered_map<int,int> freq;

        for(int i=0; i<arr.size(); i++){
            freq[arr[i]]++;
        }

        for(auto f: freq){
            if(f.first == f.second){
                result = max(result, f.first);
            }
        }
        return result;
    }
};