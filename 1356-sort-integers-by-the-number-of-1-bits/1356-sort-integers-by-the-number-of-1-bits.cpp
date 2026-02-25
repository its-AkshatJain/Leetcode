class Solution {
public:
    int oneBitCount(int num){
        int count = 0;
        while(num){
            count += num&1;
            num = num>>1;
        }
        return count;
    }
    vector<int> sortByBits(vector<int>& arr) {
        auto lambda = [&](int &a, int &b){
            int count_a = oneBitCount(a);
            int count_b = oneBitCount(b);

            if(count_a == count_b){
                return a < b;
            }
            return count_a < count_b;
        };

        sort(arr.begin(), arr.end(), lambda);
        return arr;
    }
};