class Solution {
public:
    int n, m;
    void solve(vector<vector<char>>& board) {
        n = board.size(), m = board[0].size();
        set<pair<int,int>> visited;
        
        for(int row = 0; row < n; row++) {
            dfs(board, visited, row, 0);
            dfs(board, visited, row, m-1);
        }
        for(int col = 0; col < m; col++) {
            dfs(board, visited, 0, col);
            dfs(board, visited, n-1, col);
        }
        
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(board[i][j] != 'N') {
                    board[i][j] = 'X';
                } else {
                    board[i][j] = 'O';
                }
            }
        }
    }
    
    void dfs(vector<vector<char>>& board, set<pair<int,int>>& visited, int row, int col) {
        if(row < 0 || row == n || col < 0 || col == m || visited.find({row,col}) != visited.end() || board[row][col] == 'X')
            return;
        
        board[row][col] = 'N';
        visited.insert({row,col});
        
        dfs(board, visited, row + 1, col);
        dfs(board, visited, row - 1, col);
        dfs(board, visited, row, col + 1);
        dfs(board, visited, row, col - 1);
    }
};

/*
'0' should not be flipped when:
on border
adjacent to a '0' that should not be flipped

problem of finding path from edges, these '0's should not be flipped
else flip everything to 'x'

*/