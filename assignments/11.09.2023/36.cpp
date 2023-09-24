class Solution {
public:
     bool isValidSudoku(vector<vector<char>>& board) {
         int row[9][9] = {0};
         int col[9][9] = {0};
         int multi[9][9] = {0};
         int num;
         for(int i = 0; i < board.size(); i++){
             for(int j = 0; j < board[0].size(); j++){
                 if(board[i][j] != '.'){
                      num = board[i][j] - '0';

                      int k = (i/3) * 3 + j/3;

                      if(row[i][num-1]++||col[j][num-1]++||multi[k][num-1]++){
                            return false;
                    }
                 }
            }
        }
        return true;
     }
};