class Solution {
public:
    void dfs(vector<vector<char>>& grid, int row, int col){
        if(row < 0 || row >= grid.size()) return;
        if(col < 0 || col >= grid[0].size()) return;
        
        if(grid[row][col] == '0') return;
        
        grid[row][col] = '0';
        
        dfs(grid, row - 1, col);
        dfs(grid, row + 1, col);
        dfs(grid, row, col + 1);
        dfs(grid, row, col - 1);
    }
    int numIslands(vector<vector<char>>& grid) {
        int row = grid.size();
        int col = grid[0].size();
        int islands = 0;
        
        for(int i = 0; i < row; i++){
            for(int j = 0; j < col; j++){
                if(grid[i][j] == '1'){
                    islands++;
                    dfs(grid, i, j);
                }
            }
        }
        return islands;
    }
};