class Solution {
    int findDigitSum(int n){
        int sum = 0;
        while(n){
            sum += n%10;
            n=n/10;
        }
        return sum;
    }
public:
    int countLargestGroup(int n) {
        unordered_map<int,int> mp;
        
        int maxSize = 0;
        int count = 0;

        for(int i=1; i<=n; i++){
            int digitSum = findDigitSum(i);

            mp[digitSum]++;

            if(mp[digitSum] == maxSize){
                count++;
            }else if(mp[digitSum] > maxSize){
                maxSize = mp[digitSum];
                count = 1;
            }
        }
        return count;
    }
};