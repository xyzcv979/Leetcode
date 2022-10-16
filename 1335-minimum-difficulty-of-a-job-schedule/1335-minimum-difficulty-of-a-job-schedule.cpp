class Solution {
public:
    int minDifficulty(vector<int>& jobDifficulty, int d) {
        int n = jobDifficulty.size();
        if(n < d) {
            return -1;
        }
        vector<vector<int>> memo(n, vector<int>(d+1,-1));
        return dfs(jobDifficulty, d, 0, memo);
    }
    
    int dfs(vector<int>& jobDifficulty, int d, int idx, vector<vector<int>>& memo) {
        int n = jobDifficulty.size();
        
        if(d == 0 && idx == n) return 0;
        if(d == 0 || idx == n) return INT_MAX;
        
        if(memo[idx][d] != -1) return memo[idx][d];
        
        int currMax = jobDifficulty[idx];
        int result = INT_MAX;
        
        for(int i = idx; i < n; i++) {
            currMax = max(currMax, jobDifficulty[i]);
            int temp = dfs(jobDifficulty, d-1, i+1, memo);
            if(temp != INT_MAX) {
                result = min(result, temp+currMax);
            }
        }
        
        return memo[idx][d] = result;
    }
};