class Solution {
public:
    int numRabbits(vector<int>& answers) {
        int n = answers.size();
        unordered_map<int,int> group_freq;
        int ans = 0;

        for(int ele: answers){
            if(ele == 0){
                ans+=1;
            }else{
                group_freq[ele]++;
                if(group_freq[ele]==ele+1){
                    ans+=group_freq[ele];
                    group_freq[ele] = 0;
                }
            }   
        }
        // Adding leftovers 
        for(auto [group,freq]: group_freq){
            if(freq>0){
                ans+= group+1;
            }
        }
        return ans;
    }
};