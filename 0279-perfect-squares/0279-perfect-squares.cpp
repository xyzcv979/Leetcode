class Solution {
public:
    int numSquares(int n) {
        vector<int> perfectSquares;
        vector<int> dp(n+1, INT_MAX);
        
        for(int i = 1; i <= sqrt(n); i++) {
            perfectSquares.push_back(i*i);
        }
        
        dp[0] = 0;
        for(int i = 1; i <= n; i++) {
            for(int s = 0; s < perfectSquares.size(); s++) {
                if(i < perfectSquares[s])
                    break;
                dp[i] = min(dp[i], dp[i-perfectSquares[s]] + 1);
            }
        }
        return dp[n];
    }
};

/*
like coin change?

have a list of pefect squares
dfs: take it or leave it on current perfect square

since we need min num that sums to n, 
start from greatest
*/