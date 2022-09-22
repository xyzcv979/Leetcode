class Solution {
public:
    string reverseWords(string s) {
        stringstream ss(s);
        string rev;
        string word;
        while(ss >> word) {
            if(rev.size() != 0)
                rev += " ";
            reverse(word.begin(), word.end());
            rev += word;
        }
        
        return rev;
    }
    
   
};