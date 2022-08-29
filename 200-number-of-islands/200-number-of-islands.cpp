class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int count = 0;
        int row = grid.size(), col = grid[0].size();
        
        for(int i = 0; i < row; i++) {
            for(int j = 0; j < col; j++) {
                if(grid[i][j] == '0') continue;
                
                queue<pair<int,int>> que;
                
                count++;
                que.push({i,j});
                
                while(!que.empty()){
                    int x = que.front().first, y = que.front().second;
                    
                    que.pop();
                    
                    if(x + 1 < row && grid[x+1][y] == '1') {
                        que.push({x+1, y});
                        grid[x+1][y] = '0';
                    }
                    if(x - 1 >= 0 && grid[x-1][y] == '1') {
                        que.push({x-1, y});
                        grid[x-1][y] = '0';
                    }
                    if(y + 1 < col && grid[x][y + 1] == '1') {
                        que.push({x, y + 1});
                        grid[x][y + 1] = '0';
                    }
                    if(y - 1 >= 0 && grid[x][y - 1] == '1') {
                        que.push({x, y - 1});
                        grid[x][y - 1] = '0';
                    }
                }
            }
        }
        
        return count;
    }
    
};