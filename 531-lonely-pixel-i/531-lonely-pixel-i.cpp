class Solution {
public:
    int findLonelyPixel(vector<vector<char>>& picture) {
        int n = picture.size(), m = picture[0].size();
        int count = 0;
        vector<int> rowCount(n,0);
        vector<int> colCount(m, 0);
        
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++){
                if(picture[i][j] == 'B') {
                    rowCount[i]++;
                    colCount[j]++;
                }
            }
        }
        
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(picture[i][j] == 'B' && rowCount[i] == 1 && colCount[j] == 1) {
                    count++;
                }
            }
        }
        
        return count;
    }
};

/*
all unique black in row and column
*/