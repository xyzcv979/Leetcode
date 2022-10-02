class Solution {
public:
    const int MOD = 1e9+7;
    vector<vector<int>> memo;
    
    int numRollsToTarget(int n, int k, int target) {
        memo = vector<vector<int>>(n+1, vector<int>(target+1, -1)); // row: n dice, col: 0 to target+1
        return dfs(n, k, target);
    }
    
    int dfs(int n, int k, int target) {
        if(target == 0) return n == 0;
        if (n == 0 || target < 0) return 0;

        // memo
        if(memo[n][target] != -1) return memo[n][target];
        
        int count = 0;
        for(int i = 1; i <= k; i++) {
            count = (count + dfs(n-1, k, target-i)) % MOD;
        }
        
        count %= MOD;
        
        memo[n][target] = count;
        return count;
    }
};

/*
n dice, k faces

number of combinations that add to target


brute force:
decrementing dice and target

top down
memoize brute force
cache keeps track of current dice number and current sum number
*/