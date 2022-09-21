class Solution {
public:
    bool isPalindrome(string s) {
        string onlyLetters;
        for(char c : s) {
            if(!isalnum(c))
                continue;
            onlyLetters += tolower(c);
        }
        
        string rev = onlyLetters;
        reverse(onlyLetters.begin(), onlyLetters.end());
        
        return rev == onlyLetters;
    }
};