class Solution {
public:
    int n, m;
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        n = heights.size(), m = heights[0].size();
        set<pair<int, int>> atlantic, pacific;
        
        // 1. first mark path from oceans to furthest reachable point
        // all of these points can reach the ocean, add to a set
        
        // for first and last row touching oceans
        for(int col = 0; col < m; col++) {
            dfs(heights, 0, col, pacific, heights[0][col]); // first row, pacific ocean
            dfs(heights, n - 1, col, atlantic, heights[n-1][col]); // last row, atlantic ocean
        }
        
        // for first and last column touching oceans
        for(int row = 0; row < n; row++) {
            dfs(heights, row, 0, pacific, heights[row][0]);
            dfs(heights, row, m - 1, atlantic, heights[row][m-1]);
        }
        
        // 2. for points that reach both oceans, add to final result
        vector<vector<int>> result;
        for(int row = 0; row < n; row++) {
            for(int col = 0; col < m; col++) {
                if(atlantic.count({row, col}) && pacific.count({row, col}))
                    result.push_back({row, col});
            }
        }
        
        return result;
        
    }
    
    void dfs(vector<vector<int>>& heights, int row, int col, set<pair<int, int>>& ocean, int prevHeight) {
        // continue if already found in ocean path. Ocean acts as a visited set
        // recall water can only flow from >= heights. Path from ocean goes from less to greater, ie climbing uphill to find path
        if(ocean.count({row, col}) || row < 0 || col < 0 || row == n || col == m || heights[row][col] < prevHeight)
            return;
        
        ocean.insert({row, col});
        
        // dfs on 4 directions
        dfs(heights, row+1, col, ocean, heights[row][col]);
        dfs(heights, row-1, col, ocean, heights[row][col]);
        dfs(heights, row, col+1, ocean, heights[row][col]);
        dfs(heights, row, col-1, ocean, heights[row][col]);
    }
};