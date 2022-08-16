class Solution {
public:
    int firstUniqChar(string s) {
        vector<int> freq(26);
        
        for(char c : s) {
            freq[c-'a']++;
        }
        
        for(int i = 0; i < s.size(); i++) {
            char currC = s[i];
            if(freq[currC - 'a'] == 1) 
                return i;
        }
        
        return -1;
    }
};