class Solution {
    #define ll long long

    bool canAssign(ll& mid, vector<int>& ranks, int cars){
        ll count = 0;
        for(ll rank: ranks){
            count+= sqrt(mid/rank);
        }
        return count>=cars;
    }
public:
    long long repairCars(vector<int>& ranks, int cars) {
        ll low = 1;
        ll high = (ll)*min_element(ranks.begin(), ranks.end()) * cars * cars;
        ll mid; 
        ll ans;

        while(low<=high){
            mid = low + (high-low)/2;
            if(canAssign(mid, ranks, cars)){
                ans = mid;
                high = mid - 1;
            }else{
                low = mid + 1;
            }
        }
        return ans;
    }
};