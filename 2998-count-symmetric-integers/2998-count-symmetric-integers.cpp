class Solution {
public:
    int countSymmetricIntegers(int low, int high) {
        int count = 0;
        for(int i=low; i<=high; i++){
             string s = to_string(i);
             if (s.size() % 2 != 0) continue; //Odd case

             int start = 0;
             int end = s.size() - 1;
             int sumStart = 0, sumEnd = 0;
             
             while(start<end){
                sumStart += s[start] - '0';
                sumEnd += s[end] - '0';
                start++;
                end--;  
             }
             if(sumStart == sumEnd) count++;
        }
        return count;
    }
};