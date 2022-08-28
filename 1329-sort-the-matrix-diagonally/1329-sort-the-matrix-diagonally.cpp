class Solution {
public:
    vector<vector<int>> diagonalSort(vector<vector<int>>& mat) {
        unordered_map<int, priority_queue<int, vector<int>, greater<int>>> diagMap;
        int n = mat.size(), m = mat[0].size();
        
        for(int row = 0; row < n; row++) {
            for(int col = 0; col < m; col++) {
                int currDiag = row - col;
                diagMap[currDiag].push(mat[row][col]);
            }
        }
        
        for(int row = 0; row < n; row++ ) {
            for(int col = 0; col < m; col++) {
                int currDiag = row - col;
                mat[row][col] = diagMap[currDiag].top();
                diagMap[currDiag].pop();
            }
        }
        
        return mat;
    }
};