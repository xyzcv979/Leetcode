class Solution {
public:
    string reverseWords(string s) {
        int left = 0;
        for(int i = 0; i < s.size(); i++){
            if(s[i] == ' '){
                reverse(s.begin() + left, s.begin() + i);
                left = i + 1;
            }
        }
        reverse(s.begin() + left, s.end());
        return s;
    }
    
   
};