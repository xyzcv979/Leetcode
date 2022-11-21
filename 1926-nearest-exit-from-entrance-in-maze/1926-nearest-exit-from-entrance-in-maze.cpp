class Solution {
public:
    int n, m;
    int nearestExit(vector<vector<char>>& maze, vector<int>& entrance) {
        n = maze.size(), m = maze[0].size();
        queue<pair<int,int>> que;
        set<pair<int,int>> visited;
        int steps = 0;
        
        que.push({entrance[0], entrance[1]});
        while(!que.empty()) {
            int size = que.size();
            for(int i = 0; i < size; i++) {
                int row = que.front().first, col = que.front().second;
                que.pop();
                
                if(row < 0 || row == n || col < 0 || col == m || maze[row][col] == '+' || visited.find({row,col}) != visited.end())
                    continue;
                if(isExit(maze, row, col) && steps != 0)
                    return steps;
                
                visited.insert({row, col});
                
                que.push({row+1, col});
                que.push({row-1, col});
                que.push({row, col+1});
                que.push({row, col-1});
            }
            steps++;
        }
        return -1;
    }
    
    bool isExit(vector<vector<char>>& maze, int row, int col) {
        return row == 0 || col == 0 || row == n-1 || col == m-1; 
    }
};

/*
shortest path to exit
bfs


["+",".","+","+","+","+","+"]
["+",".","+",".",".",".","+"]
["+",".","+",".","+",".","+"]
["+",".",".",".",".",".","+"]
["+","+","+","+",".","+","."]


*/