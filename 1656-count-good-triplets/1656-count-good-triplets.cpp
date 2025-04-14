class Solution {
public:
    int countGoodTriplets(vector<int>& arr, int a, int b, int c) {
        if(arr.size() < 3) return 0;
        int count = 0;
        for(int i=0; i<arr.size()-2; i++){
            for(int j=i+1; j<arr.size()-1; j++){
                for(int k=j+1; k<arr.size(); k++){
                    int x = arr[i];
                    int y = arr[j];
                    int z = arr[k];

                    if(abs(x-y)<=a && abs(y-z)<=b &&abs(x-z)<=c){
                        count++;
                    }
                }
            }
        }
        return count;
    }
};