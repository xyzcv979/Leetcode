class Solution {
public:
    int m, n;
    vector<int> findBall(vector<vector<int>>& grid) {
        m = grid.size(), n = grid[0].size();
        
        vector<int> ans(n);
        for(int col = 0; col < n; col++) {
            ans[col] = dfs(grid, 0, col);
        }
        
        return ans;
    }
    
    int dfs(vector<vector<int>>& grid, int row, int col) {
        if(row == m) return col;
        
        int nextCol = col + grid[row][col];
        if(nextCol < 0 || nextCol > n-1 || grid[row][col] != grid[row][nextCol]) {
            return -1;
        }
        
        return dfs(grid, row+1, nextCol);
    }
};

/*
stuck = V shape. 1,-1 or -1,1 
        or against side 
          column = 0, -1
          column = n-1, 1
if dir = 1 check column+1 for -1
if dir = -1, check column-1 for 1

ball moves diagonally
row+1,col+1
or
row-1,col+1

so, if dir == 1, check row,col+1, move to row+1,col+1
    if dir == -1, check row,col-1, move to row+1,col-1

return column or -1
*/