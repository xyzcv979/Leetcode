class Solution {
public:
    vector<vector<int>> findWinners(vector<vector<int>>& matches) {
        unordered_map<int,int> winLoss;
        
        for(auto match : matches) {
            if(winLoss.find(match[0]) == winLoss.end())
                winLoss[match[0]] = 0;
            winLoss[match[1]]--;
        }
        
        vector<vector<int>> ans(2, vector<int>());
        for(auto it : winLoss) {
            if(it.second == 0)
                ans[0].push_back(it.first);
            else if(it.second == -1) 
                ans[1].push_back(it.first);
        }
        sort(ans[0].begin(), ans[0].end());
        sort(ans[1].begin(), ans[1].end());
        
        return ans;
    }
};