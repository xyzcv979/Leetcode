class Solution {
public:
    int n, m;
    bool exist(vector<vector<char>>& board, string word) {
        n = board.size(), m = board[0].size();
        
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(board[i][j] == word[0]) {
                    if(dfs(board, word, 0, i, j))
                        return true;
                }
            }
        }
        return false;
    }  
    
    bool dfs(vector<vector<char>>& board, string word, int idx, int row, int col) {
        if(idx == word.size())
            return true;
        
        if(row < 0 || row == n || col < 0 || col == m || board[row][col] != word[idx])
            return false;

        // Backtrack
        char temp = board[row][col];
        board[row][col] = '.';
        bool isValid;
        isValid = dfs(board,word,idx+1,row+1, col) ||                   dfs(board,word,idx+1,row-1, col) || 
            dfs(board,word,idx+1,row, col+1) ||
            dfs(board,word,idx+1,row, col-1);

        board[row][col] = temp;
        
        return isValid;
    }
};

/*
backtracking
try one char, erase it and try another char
all 4 directions

can't do dfs with visited set because you're revisiting spots on other dfs calls so they interfere with each other

need backtrack, set to 'visited' and set it back
*/