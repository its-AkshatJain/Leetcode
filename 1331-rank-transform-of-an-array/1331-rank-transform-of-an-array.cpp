class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        int n = arr.size();
        vector<int> temp = arr;
        sort(temp.begin(), temp.end());

        unordered_map<int, int> rank;
        int currRank = 1;

        for(int i=0; i<n; i++){
            if(i>0 && temp[i-1] !=temp[i]){
                currRank++;
            }
            rank[temp[i]] = currRank;
        }

        for(int i=0; i<n; i++){
            arr[i] = rank[arr[i]];
        }
        return arr;
    }
};