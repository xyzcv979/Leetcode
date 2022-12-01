class Solution {
public:
    bool halvesAreAlike(string s) {
        unordered_set<char> vowels = {
            'a','e','i','o','u',
            'A','E','I','O','U'
        };
        
        int firstCount = 0, secondCount = 0;
        
        for(int i = 0; i < s.size()/2; i++) {
            if(vowels.find(s[i]) != vowels.end())
                firstCount++;
            if(vowels.find(s[s.size()-i-1]) != vowels.end()) 
                secondCount++;
        }
        
        return firstCount == secondCount;
    }
};