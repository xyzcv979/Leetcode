class Solution {
public:
    
    void dfs(vector<vector<char>>& grid, int row, int col){
        int rowLen = grid.size();
        int colLen = grid[0].size();
        
        if(row < 0 || col < 0 || row >= rowLen || col >= colLen || grid[row][col] == '0')
            return;
        
        grid[row][col] = '0';
        dfs(grid, row - 1, col);
        dfs(grid, row + 1, col);
        dfs(grid, row, col - 1);
        dfs(grid, row, col + 1);
    }
    
    int numIslands(vector<vector<char>>& grid) {
        int rowLen = grid.size();
        int colLen = grid[0].size();
        int numOfIslands = 0;
        
        for(int i = 0; i < rowLen; i++){
            for(int j = 0; j < colLen; j++){
                if(grid[i][j] == '1'){
                    numOfIslands++;
                    dfs(grid, i, j);
                }
            }
        }
        
        return numOfIslands;
    }
};