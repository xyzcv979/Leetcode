class Solution {
public:
    void wallsAndGates(vector<vector<int>>& rooms) {
        int n = rooms.size(), m = rooms[0].size();
        queue<pair<int,int>> que;
        set<pair<int,int>> visited;
        
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(rooms[i][j] == 0) {
                    que.push({i,j});
                }
            }
        }
        
        int dist = 0;
        while(!que.empty()) {
            int size = que.size();
            for(int i = 0; i < size; i++) {
                int row = que.front().first, col = que.front().second;
                que.pop();
                
                if(row < 0 || row == n || col < 0 || col == m || rooms[row][col] == -1 || visited.find({row,col}) != visited.end()) {
                    continue;
                }
                
                visited.insert({row,col});
                if(rooms[row][col] != 0) { // not a gate
                    rooms[row][col] = dist;
                }
                
                que.push({row+1,col});
                que.push({row-1,col});
                que.push({row,col+1});
                que.push({row,col-1});
            }
            dist++;
        }
    }
};

/*
bfs, each floor is the dist to nearest gate
for every gate,

visited set probably wont work here cause we need to check the square for minimum dist

since we are doing BFS, whenever we encounter a spot that is not infinity, we know that is the min distance
starting from all gates at dist 0, as we expand outwards, the dist is set at equal values from all gates

*/