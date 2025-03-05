class Solution {
public:
    long long coloredCells(int n) {
        long long count =1;
        long long jump_size = 4;
        while(n>1){
            count += jump_size;
            jump_size += 4;
            n--;
        }
        return count;
    }
};