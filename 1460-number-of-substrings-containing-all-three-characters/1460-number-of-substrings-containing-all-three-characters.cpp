class Solution {
public:
    int numberOfSubstrings(string s) {
       vector<int> freq(3,0);
       int n = s.size();
       int subarrays = 0;

       int left = 0;
       int right = 0;

       while(right < n){
        freq[s[right] - 'a']++;

        // If all freq is > 0 slide window
        while(freq[0]>0 && freq[1]>0 && freq[2]>0){
            subarrays += n - right;
            freq[s[left] - 'a']--;
            left++;
        }
        right++;
       }
       return subarrays; 
    }
};