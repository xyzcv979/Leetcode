class Solution {
public:
    vector<vector<int>> memo;
    const int MOD = 1e9+7;
    int numRollsToTarget(int n, int k, int target) {
        memo =  vector<vector<int>>(n+1, vector<int>(target+1,-1));
        return dfs(n, k, target);
    }
    
    int dfs(int n, int k, int target) {
        if(target == 0) {
            return n == 0;
        }
        if(n == 0 || target < 0) {
            return 0;
        }
        if(memo[n][target] != -1)
            return memo[n][target];
        

        int possibleWays = 0;
        for(int i = 1; i <= k; i++) {
            possibleWays = (possibleWays + dfs(n - 1, k, target-i))%MOD;
        }
        
        memo[n][target] = possibleWays;
        return possibleWays;
    }
};

/*
states: dice face, sum



*/