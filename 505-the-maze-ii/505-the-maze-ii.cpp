class Solution {
    const vector<vector<int>> Dirs = {{0, -1}, {0, 1}, {1, 0}, {-1, 0} };

    bool isValid(int x, int y, const vector<vector<int>>& maze) {
        return x >= 0 && x < maze.size() && 
               y >= 0 && y < maze[0].size() &&
               maze[x][y] <= 0; 
    }
    
	// each element has x, y, and the total distance
    using P = vector<int>;
    struct Comparator {
        bool operator()(const P& a, const P& b) {
            return a[2] > b[2]; // need a min heap based on distance
        }  
    };
    
public:
    int shortestDistance(vector<vector<int>>& maze, vector<int>& start, vector<int>& dest) {
        if (maze.empty()) return false;
        
        priority_queue<P, vector<P>, Comparator> q;
        q.push({start[0], start[1], 0});
        
        while (!q.empty()) {
            auto p = q.top();
            q.pop();
        
            if (p[0] == dest[0] && p[1] == dest[1]) {
                return p[2];
            }
            
            if (maze[p[0]][p[1]] == -1) continue;
			// maze is modifiable and since we will never use this position again, we mark it as visited (-1)
            maze[p[0]][p[1]] = -1;
        
            
            for (const auto& d : Dirs) {
                int steps = 0;
                int x = p[0];
                int y = p[1];
                while (isValid(x + d[0], y + d[1], maze)) {
                    x += d[0];
                    y += d[1];
                    steps++;
                }
                
                if (maze[x][y] == 0) {
                    q.push({x, y, p[2] + steps});    
                }
            }        
        }
        
        return -1;        
    }
};
