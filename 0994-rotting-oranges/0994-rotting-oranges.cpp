class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        queue<pair<int,int>> que;
        set<pair<int,int>> visited;
        int minCount = -1;
        
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(grid[i][j] == 2) { // rotten oranges
                    que.push({i,j});
                }
            }
        }
        
        while(!que.empty()) {
            int size = que.size();

            for(int i = 0; i < size; i++) {
                pair<int,int> curr = que.front();
                int x = curr.first, y = curr.second;
                que.pop();
                
                if(x < 0 || x == n || y < 0 || y == m || visited.find({x,y}) != visited.end() || grid[x][y] == 0)
                    continue;
                
                grid[x][y] = 2;
                visited.insert({x,y});
                
                que.push({x+1, y});
                que.push({x-1, y});
                que.push({x, y+1});
                que.push({x, y-1});
                
            }
            
            minCount++;
        }
        
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(grid[i][j] == 1) { // got a fresh orange
                    return -1;
                }
            }
        }
        return minCount == -1 ? 0 : minCount-1;
    }
};