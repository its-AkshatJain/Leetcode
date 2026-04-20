class Solution {
public:
    int maxDistance(vector<int>& colors) {
        int n = colors.size();
        int result = 0;

        int i=0;
        while(colors[i] == colors[n-1]) i++;
        
        result = max(result, abs(i - (n-1)) );

        i = n-1;
        while(colors[0] == colors[i]) i--;
        
        result = max(result, i);

        return result;
    }
};