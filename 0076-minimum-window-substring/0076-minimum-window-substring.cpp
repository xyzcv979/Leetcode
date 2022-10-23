class Solution {
public:
    string minWindow(string s, string t) {
        int n = t.size();
        unordered_map<char, int> tMap;
        
        for(char c : t) {
            tMap[c]++;
        }
        
        int left = 0, right = 0, minLen = INT_MAX, minLeft = 0, count = t.size();
        while(right < s.size()) {
            char sRight = s[right];
            
            if(tMap[sRight] > 0)
                count--;
            
            tMap[sRight]--;
             
            // move left ptr if valid window
 
            while(count == 0) {
                char sLeft = s[left];
                int currWindowLen = right - left + 1;
                if(currWindowLen < minLen) {
                    minLen = currWindowLen;
                    minLeft = left;
                }
                tMap[sLeft]++;
                if(tMap[sLeft] > 0) {
                    count++;
                }
                left++;
            }
            right++;
            
        }
        
        if(minLen == INT_MAX) return "";
        return s.substr(minLeft, minLen);
    }
};

/*
move left ptr if the window is still valid to get min window
valid window = every char in t is in window

2 hashmaps?
*/