class Solution {
public:
    bool isAnagram(string s, string t) {
        vector<int> sCount(26);
        vector<int> tCount(26);
        for(char c : s)
            sCount[c - 'a']++;
        for(char c : t)
            tCount[c - 'a']++;
        for(int i = 0; i < 26; i++){
            if(sCount[i] != tCount[i])
                return false;
        }
        return true;
    }
};