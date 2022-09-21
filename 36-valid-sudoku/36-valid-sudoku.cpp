class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        int n = board.size();
        
        for(int row = 0; row < n; row++) {
            unordered_set<int> rowSet, colSet, nineSet;
            for(int col = 0; col < n; col++) {
                
                char rowChar = board[row][col];
                char colChar = board[col][row];
                  
                if(rowChar!= '.') {
                    if(rowSet.count(rowChar))
                        return false;
                     rowSet.insert(rowChar);
                }
               
                if(colChar != '.') {
                    if(colSet.count(colChar))
                        return false;
                     colSet.insert(colChar);
                }
                
            
                int nineRow = 3 * (row / 3) + (col/3);                     
                int nineCol = 3 * (row % 3) + (col%3);
                char nineChar = board[nineRow][nineCol];
                
                if(nineChar != '.') {
                    if(nineSet.count(nineChar))
                        return false;
                    nineSet.insert(nineChar);
                }
               
            }
        }
        
        return true;
    }
};