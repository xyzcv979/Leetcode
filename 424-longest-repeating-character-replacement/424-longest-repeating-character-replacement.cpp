class Solution {
public:
    int characterReplacement(string s, int k) {
        unordered_map<char, int> counts;
        int maxCount = 0;
        int left = 0, right = 0;
        int longestSub = 0;
        
        while(right < s.size()) {
            char curr = s[right];
            counts[curr]++;
            maxCount = max(maxCount, counts[curr]);
            
            int windowLen = right - left + 1;
            while(windowLen > maxCount + k) {
                counts[s[left]]--;
                left++;
                windowLen = right - left + 1;
            }
            longestSub = right - left + 1;
            right++;
        }
        
        return longestSub;
    }
};

/*
k letters + max same letter

up to k letters + 1
*/