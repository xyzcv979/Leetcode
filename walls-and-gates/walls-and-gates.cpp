class Solution {
public:
    void wallsAndGates(vector<vector<int>>& rooms) {
        int inf = INT_MAX;
        vector<pair<int,int>> dir = {{1,0}, {-1, 0}, {0, 1}, {0, -1}};
        
        int m = rooms.size(), n = rooms[0].size();
        queue<pair<int, int>> que;
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(rooms[i][j] == 0) // Insert gates into queue
                    que.emplace(i,j);
            }
        }
        
         while(!que.empty()){
             int x = que.front().first, y = que.front().second;
             que.pop();
             
             for(auto it : dir){
                 int r = x + it.first, c = y + it.second;
                if(r < 0 || c < 0 || r >= m || c >= n || rooms[r][c] <= rooms[x][y] + 1)
                    continue;
                 rooms[r][c] = rooms[x][y] + 1;
                 que.emplace(r,c);
             }
         }
    }
};