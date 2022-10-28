class Solution {
public:
    int minTotalDistance(vector<vector<int>>& grid) {
        vector<int> rows;
        vector<int> cols;
        
        for(int row = 0; row < grid.size(); row++) {
            for(int col = 0; col < grid[row].size(); col++) {
                if(grid[row][col] == 1) {
                    rows.push_back(row);
                    cols.push_back(col);
                }
            }
        }
        
        int row = rows[rows.size()/2];
        // note we don't sort rows
        sort(cols.begin(), cols.end());
        int col = cols[cols.size()/2];
        return minDist1D(rows, row) + minDist1D(cols,col);
    }   
    
    int minDist1D(vector<int> points, int origin) {
        int dist = 0;
        for(int point : points) {
            dist += abs(point - origin);
        }
        return dist;
    }
};

// manhattan distance = sum of 2 independent variables
// solve both as 1d problems
// median must be optimal meeting point
// sort, select by middle elements
//