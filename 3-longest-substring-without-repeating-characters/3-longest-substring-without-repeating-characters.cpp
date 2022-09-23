class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int longestSub = 0;
        unordered_set<char> seen;
        
        int left = 0, right = 0;
        while(right < s.size()) {
            char curr = s[right];
            while(seen.count(curr)) {
                seen.erase(s[left]);
                left++;
            } 
            seen.insert(curr);
            longestSub = max(longestSub, right - left + 1);
            right++;
        }
        
        return longestSub;
    }
};