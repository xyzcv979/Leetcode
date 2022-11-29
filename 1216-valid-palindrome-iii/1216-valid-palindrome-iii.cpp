class Solution {
public:
    vector<vector<int>> memo;
    bool isValidPalindrome(string s, int k) {
        memo = vector<vector<int>>(s.size(), vector<int>(s.size(), -1));
        return dfs(s, 0, s.size()-1) <= k;
    }
    
    int dfs(string& s, int left, int right) {
        if(left == right) return 0;
        if(left == right - 1) return s[left] != s[right];
        
        if(memo[left][right] != -1)
            return memo[left][right];
        
        int k;
        if(s[left] != s[right]) {
            k = 1 + min(dfs(s,left+1, right), dfs(s,left,right-1));
        } else {
            k = dfs(s,left+1,right-1);
        }
        
        memo[left][right] = k;
        return k;
    }
};

/*
remove up to k elements to make palindrome

dfs, take it or leave it
either move right or left pointer when they mismatch

bacabaaa
acabaaa
cabaa
abaa
*/