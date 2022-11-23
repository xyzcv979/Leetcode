class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        int n = board.size(), m = board[0].size();
        vector<set<char>> rowSet(9), colSet(9), boxSet(9);
        
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                char curr = board[i][j];
                if(curr == '.')
                    continue;
                
                if(rowSet[i].count(curr) || colSet[j].count(curr) || boxSet[3*(i/3)+(j/3)].count(curr))
                    return false;
                rowSet[i].insert(curr);
                colSet[j].insert(curr);
                boxSet[3*(i/3)+(j/3)].insert(curr);
            }
        }
        return true;
    }
};
/*

*/