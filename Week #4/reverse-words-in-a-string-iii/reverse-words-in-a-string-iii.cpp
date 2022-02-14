class Solution {
public:
    string reverseWords(string s) {
        stringstream ss(s);
        string word;
        string ret = "";
        while(ss >> word){
            reverseWord(word);
            ret.append(word);
            ret.append(" ");
        }
        return ret.substr(0, ret.size() - 1);
    }
    
    void reverseWord(string &s){
        int left = 0;
        int right = s.size() - 1;
        while(left < right){
            char temp = s[left];
            s[left] = s[right];
            s[right] = temp;
            left++;
            right--;
        }
    }
};