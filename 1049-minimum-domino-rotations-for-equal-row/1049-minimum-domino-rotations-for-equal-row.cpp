class Solution {
    int countRotation(int target, vector<int>& first, vector<int>& second){
        int count = 0;
        for(int i=0; i<first.size(); i++){
            if(first[i] == target) continue;
            else if(second[i] == target) count++;
            else return INT_MAX;
        }
        return count;
    }
public:
    int minDominoRotations(vector<int>& tops, vector<int>& bottoms) {
        int min_rotations = INT_MAX;
        for(int i=1; i<=6; i++){
            int count_tops = countRotation(i, tops, bottoms);
            int count_bottoms = INT_MAX;
            if(count_tops!=INT_MAX){
                count_bottoms = countRotation(i, bottoms, tops);
            }
            min_rotations = min(min_rotations, min(count_tops, count_bottoms));
        } 
        return (min_rotations==INT_MAX)?-1:min_rotations;                                                        
    }
};