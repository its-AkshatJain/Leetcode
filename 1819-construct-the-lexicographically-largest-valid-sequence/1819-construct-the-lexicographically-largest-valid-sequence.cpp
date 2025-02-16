class Solution {
    bool findLargest(vector<int> &res, vector<bool> &used, int pos, int n){
        if(pos == 2*n-1) return true;
        if(res[pos]!=0){ //Already filled
            return findLargest(res, used, pos+1, n);
        }

        for(int i=n; i>0; i--){
            if(used[i]) continue;

            used[i] = true;
            res[pos] = i;
            if(i==1 and findLargest(res, used, pos+1, n)){
                return true;
            }else if(i>1 and (pos+i)<(2*n-1) and res[pos+i]==0){
                res[pos+i] = i;
                if(findLargest(res, used, pos+1, n)){
                    return true;
                }
                res[pos+i] = 0;
            }
            used[i] = false;
            res[pos] = 0;
        }
        return false;
    }
public:
    vector<int> constructDistancedSequence(int n) {
        vector<int> res(2*n-1, 0);
        vector<bool> used(n+1, false);

        findLargest(res, used, 0, n);
        return res;
    }
};