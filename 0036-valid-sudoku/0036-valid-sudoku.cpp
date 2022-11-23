class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        int n = board.size(), m = board[0].size();
        
        for(int i = 0; i < n; i++) {
            unordered_set<char> rowSet, colSet, boxSet;
            for(int j = 0; j < m; j++) {
                
                char rowVal = board[i][j];
                char colVal = board[j][i];
                
                int boxRow = 3 * (i/3) + (j/3);
                int boxCol = 3 * (i%3) + (j%3);
                char boxVal = board[boxRow][boxCol];

                if(rowVal != '.') {
                    if(rowSet.count(rowVal))
                        return false;
                    rowSet.insert(rowVal);
                }
                
               if(colVal != '.') {
                    if(colSet.count(colVal))
                        return false;
                    colSet.insert(colVal);
                }
                
                if(boxVal != '.') {
                    if(boxSet.count(boxVal))
                        return false;
                    boxSet.insert(boxVal);
                }
            }
        }
        return true;
    }
};
/*

*/