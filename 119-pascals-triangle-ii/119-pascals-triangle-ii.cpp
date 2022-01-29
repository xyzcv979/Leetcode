class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> cur, prev;
        for(int i = 0; i <= rowIndex; i++){
            cur.assign(i + 1, 1);
            for(int j = 1; j < i; j++){
                cur[j] = prev[j-1] + prev[j];
            }
            prev = move(cur);
        }
        return prev;
    }
};