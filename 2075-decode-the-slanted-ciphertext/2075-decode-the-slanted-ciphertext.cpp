class Solution {
public:
    string decodeCiphertext(string encodedText, int rows) {
        int l = encodedText.length();
        int columns = l/rows;

        vector<vector<char>> mat(rows, vector<char>(columns));
        string originalText;

        int index = 0;
        for(int i = 0; i < rows; i++){
            for(int j = 0; j < columns; j++){
                mat[i][j] = encodedText[index++];
            }
        }

        for(int col=0; col<columns; col++){
            int i = 0;
            int j = col;
            while(i<rows && j<columns){
                originalText += mat[i][j];
                i++;
                j++;
            }
        }

        while(!originalText.empty() && originalText.back() == ' '){
            originalText.pop_back();
        }

        return originalText;
    }
};