class Solution {
public:
    int maxIceCream(vector<int>& costs, int coins) {
        int iceCreamCount = 0;
        vector<int> freq(100001);

        for(int cost: costs){
            freq[cost]++;
        }

        for(int price=1; price<=100000; price++){
            while(freq[price] > 0 && coins >= price){
                coins -= price;
                iceCreamCount++;
                freq[price]--;
            }
        }

        return iceCreamCount;
    }
};