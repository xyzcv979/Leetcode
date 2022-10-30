class Solution {
public:
    int getFood(vector<vector<char>>& grid) {
        int n = grid.size(), m = grid[0].size();
        queue<vector<int>> que;
        vector<vector<bool>> seen(n, vector<bool>(m, false));
        vector<vector<int>> dir = {
                {-1,0},
            {0,-1},  {0,1},
                 {1,0}
        };
        
        // insert starting pos into queue;
        bool foundStart = false;
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(grid[i][j] == '*') {
                    que.push({i, j, 0});
                    foundStart = true;
                    break;
                }
            }
            if(foundStart)
                break;
        }
        
        unordered_set<int> stepsFoundFood;
        while(!que.empty()) {
            auto front = que.front();
            int x = front[0], y = front[1], steps = front[2];
            
            que.pop();
            
            if(x < 0 || x >= n || y < 0 || y >= m || grid[x][y] == 'X' || seen[x][y]) {
                continue;
            }
            
            // Found food
            if(grid[x][y] == '#') {
                return steps;
            }
            
            // Push up,left,right,down
            for(auto coord : dir) {
                que.push({x+coord[0], y+coord[1], steps+1});
            }
            seen[x][y] = true;
        }
        
        
        return -1;
    }
};

/*
state: keep track of steps

does seen array need to keep track of steps? 
or is it just true/false visited
*/