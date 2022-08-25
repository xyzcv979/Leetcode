class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        unordered_map<int,int> freq;
        
        for(char c : magazine)
            freq[c]++;
        
        for(char c : ransomNote) {
            if(freq[c] <= 0)
                return false;
            freq[c]--;
        }
        
        return true;
    }
};