class Solution {
public:
    vector<vector<int>> removeInterval(vector<vector<int>>& intervals, vector<int>& toBeRemoved) {
        int n = intervals.size();
        vector<vector<int>> ans;
        
        int removeStart = toBeRemoved[0], removeEnd = toBeRemoved[1];
        for(int i = 0; i < n; i++) {
            int currStart = intervals[i][0], currEnd = intervals[i][1];
            
            if(currStart >= removeEnd || currEnd <= removeStart) {
                ans.push_back({currStart, currEnd});
            } else {
                if(currStart < removeStart) {
                    ans.push_back({currStart, removeStart});
                }
                if(currEnd > removeEnd) {
                    ans.push_back({removeEnd, currEnd});
                }
            }
        }
        
        return ans;
    }
};

/*
-5 -4 -3 -2 -1 0 1 2 3 4 5 6 7 8 9
             -----------

*/