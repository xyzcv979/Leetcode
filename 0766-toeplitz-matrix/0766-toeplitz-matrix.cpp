class Solution {
public:
    bool isToeplitzMatrix(vector<vector<int>>& matrix) {
        int n = matrix.size(), m = matrix[0].size();
        
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(i + 1 < n && j + 1 < m) {
                    if(matrix[i+1][j+1] != matrix[i][j])
                        return false;
                }
            }
        }
        return true;
    }
};