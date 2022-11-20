class Solution {
public:
    int n, m;
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        n = heights.size(), m = heights[0].size();
        set<pair<int,int>> atlantic, pacific;
        
        for(int col = 0; col < m; col++) {
            dfs(heights, 0, col, pacific, heights[0][col]);
            dfs(heights, n-1, col, atlantic, heights[n-1][col]);
        }
                
        for(int row = 0; row < n; row++) {
            dfs(heights, row, 0, pacific, heights[row][0]);
            dfs(heights, row, m-1, atlantic, heights[row][m-1]);
        }
        
        vector<vector<int>> ans;
        for(auto pair : atlantic) {
            if(pacific.find(pair) != pacific.end()) {
                ans.push_back({pair.first, pair.second});
            }
        }
        return ans;
        
    }
    
    void dfs(vector<vector<int>>& heights, int row, int col, set<pair<int, int>>& ocean, int prevHeight) {
        if(row < 0 || row == n || col < 0 || col == m || ocean.find({row,col}) != ocean.end() || heights[row][col] < prevHeight)
            return;
        
        ocean.insert({row,col});
        prevHeight = heights[row][col];
        
        dfs(heights, row + 1, col, ocean, prevHeight);
        dfs(heights, row - 1, col, ocean, prevHeight);
        dfs(heights, row, col + 1, ocean, prevHeight);
        dfs(heights, row, col - 1, ocean, prevHeight);
    }
};

/*
Start from 1 ocean
get paths

start from other ocean

get intersecting paths

*/