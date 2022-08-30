class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        transpose(matrix);
        reverseRows(matrix);
        
        
    }
    
    void reverseRows(vector<vector<int>>& matrix) {
        for(int row = 0; row < matrix.size(); row++) {
            reverse(matrix[row].begin(), matrix[row].end());
        }
    }
    
    void transpose(vector<vector<int>>& matrix) {
        for(int row = 0; row < matrix.size(); row++) {
            for(int col = row + 1; col < matrix[row].size(); col++) {
                int temp = matrix[row][col];
                matrix[row][col] = matrix[col][row];
                matrix[col][row] = temp;
            }
        }
    }
};

/*
reverse, transpose


[3,2,1]
[6,5,4]
[9,8,7]

[7,4,1]
[8,5,2]
[9,6,3]

*/