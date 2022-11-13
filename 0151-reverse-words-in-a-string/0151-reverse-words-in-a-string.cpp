class Solution {
public:    
    string reverseWords(string s) {
        stringstream ss(s);
        string word;
        stack<string> stck;
        
        while(ss >> word) {
            stck.push(word);
        }
        
        string ans = "";
        while(!stck.empty()) {
            ans += stck.top() + " ";
            stck.pop();
        }
        
        return ans.substr(0, ans.size()-1);
    }
};