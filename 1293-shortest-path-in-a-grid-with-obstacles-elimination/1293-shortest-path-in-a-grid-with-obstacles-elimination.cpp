class Solution {
public:
    int shortestPath(vector<vector<int>>& grid, int k) {
        int n = grid.size(), m = grid[0].size();
        queue<vector<int>> que; // x, y, removedCount, steps
        vector<vector<int>> seen(n, vector<int>(m, -1)); // seen to keep track of current removed on x,y
        vector<pair<int,int>> dir = { // 0:up 1:left, 2:right, 3:down
                 {-1,0},
            {0,-1},   {0,1},
                 {1, 0}
        };
        
        que.push({0,0,0,0});
        while(!que.empty()) {
            auto front = que.front();
            int x = front[0], y = front[1], removedCount = front[2], steps = front[3];
            que.pop();
            
            if(x < 0 || x >= n || y < 0 || y >= m) {
                continue;
            }
            
            // if obstacle, decrement remv
            if(grid[x][y] == 1) {
                removedCount++;
                if(removedCount > k) { // can't remove anymore obstacles
                    continue;
                }
            }
            
            // Reached end
            if(x == n - 1 && y == m - 1) {
                return steps;
            }
            
            // If visited already AND seen[x][y] is a visited removedCount
            if(seen[x][y] != -1 && seen[x][y] <= removedCount) {
                continue;
            }
            
            // Move up, left, right, down, add to queue
            for(auto pairDir : dir) {
                que.push({x + pairDir.first, y + pairDir.second, removedCount, steps+1});
            }

            seen[x][y] = removedCount;
            
        }
        
        return -1;
    }
};

/*
seen list
move left, right, up, down

can remove at most k obstacles
keep track of current rmved obstacles
moves that encounter obstacle still valid if remved <= k

bfs(x,y,r)

*/