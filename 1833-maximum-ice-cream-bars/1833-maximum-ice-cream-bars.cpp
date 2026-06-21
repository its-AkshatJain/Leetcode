class Solution {
public:
    int maxIceCream(vector<int>& costs, int coins) {
        sort(costs.begin(), costs.end());
        int iceCreamCount = 0;

        for(int i=0; i<costs.size(); i++){
            if(coins >= costs[i]){
                 iceCreamCount++;
                 coins -= costs[i];
            }else{
                break;
            }
        }

        return iceCreamCount;
    }
};