class Solution {
public:
    string minWindow(string s, string t) {
        int m = s.size(), n = t.size();
        unordered_map<char,int> tFreq;
        int left = 0, right = 0;
        int count = 0; // number of valid chars in window
        int minStart = 0, minLen = INT_MAX;
        
        for(char c : t) {
            tFreq[c]++;
        }
        
        while(right < m) {
            char curr = s[right];
            
            if(tFreq[curr] > 0) count++;
            tFreq[curr]--;
            
            if(count == n) {
                while(left < right && tFreq[s[left]] < 0) {
                    tFreq[s[left]]++;
                    left++;
                }
                if(minLen > (right - left + 1)) {
                    minLen = right - left + 1;
                    minStart = left;
                }
            }
            
           right++;
        }
        
        if(minLen == INT_MAX) return "";
        return s.substr(minStart, minLen);
    }
};

/*
closest left char
closest right char

s = baacabac  t = cba

baac
acab
abac
bac
*/