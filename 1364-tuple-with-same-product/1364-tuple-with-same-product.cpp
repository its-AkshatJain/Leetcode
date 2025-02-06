class Solution {
    int nC2(int n){
        return n*(n-1)/2;
    }
public:
    int tupleSameProduct(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int,int> freq;

        for(int i=0; i<n; i++){
            for(int j=i+1; j<n; j++){
                freq[nums[i]*nums[j]]++;
            }
        }

        int count = 0;
        for(auto [product, frequency]: freq){
            count += 8 * nC2(frequency);
        }
        return count;
    }
};