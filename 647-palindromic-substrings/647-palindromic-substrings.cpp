class Solution {
 public:
    int countSubstrings(string s) {
        int ans = 0;
        for(int i = 0; i < s.size(); i++){
            ans += countAroundCenter(s, i, i); // Odd
            ans += countAroundCenter(s, i, i + 1); // Even;
        }
        return ans;
    }
    
    int countAroundCenter(string s, int left, int right){
        int count = 0;
        while(left >= 0 && right < s.size() && s[left] == s[right]){
            count++;
            left--;
            right++;
        }
        return count;
    }
};