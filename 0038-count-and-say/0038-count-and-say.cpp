class Solution {
public:
    string countAndSay(int n) {
        string s = "1";
        for(int i = 1; i < n ; i++) {
            s = sayNumbers(s);
        }
        return s;
    }
    
    string sayNumbers(string s) {
        int left = 0, right = 0;
        string result = "";
        
        while(right < s.size()) {
            if(s[left] != s[right]) {
                result += to_string(right - left);
                result += s[left];
                left = right;
            }
            right++;
        }
        
        result += to_string(right - left);
        result += s[left];
        
        return result;
    }
};