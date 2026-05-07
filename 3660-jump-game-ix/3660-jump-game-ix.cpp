class Solution {
public:
    vector<int> maxValue(vector<int>& nums) {
        int n = nums.size();
        vector<int> prefixMx(n);
        vector<int> suffixMn(n);

        prefixMx[0] = nums[0];
        for(int i=1; i<n; i++){
            prefixMx[i] = max(prefixMx[i-1], nums[i]);
        }

        suffixMn[n-1] = nums[n-1];
        for(int i=n-2; i>=0; i--){
            suffixMn[i] = min(suffixMn[i+1], nums[i]);
        }

        vector<int> result(n, 0);
        result[n-1] = prefixMx[n-1];
        for(int i=n-2; i>=0; i--){
            if(prefixMx[i] > suffixMn[i+1]){
                result[i] = result[i+1];
            }else{
                result[i] = prefixMx[i];
            }
        }

        return result;
    }
};