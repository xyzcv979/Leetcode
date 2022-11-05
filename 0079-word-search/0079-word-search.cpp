class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        // find starting position for word[0]
        
        for(int i = 0; i < board.size(); i++) {
            for(int j = 0; j < board[i].size(); j++) {
                if(word[0] == board[i][j]) {
                    bool isTrue = false;
                    isTrue = dfs(board, word, i, j, 0);
                    if(isTrue) return true;
                }
            }
        }
        return false;
    }
    
    bool dfs(vector<vector<char>>& board, string word, int row, int col, int index) {
        if(index == word.size()) return true;
        if(row < 0 || row == board.size() || col < 0 ||
           col == board[0].size() || word[index] != board[row][col]) return false;
        
        char temp = board[row][col];
        board[row][col] = ' ';
        // dfs on left, right, up, down
        bool isValid = dfs(board, word, row,col+1, index+1) || dfs(board, word, row+1,col, index+1)
                        || dfs(board, word, row, col-1, index+1) || dfs(board, word, row - 1, col, index+1);
        board[row][col] = temp; // backtrack
        
        return isValid;
    }
};