class Solution {
public:
    string removeDuplicates(string s) {
        stack<char> stck;
        
        for(char c : s) {
            if(!stck.empty() && c == stck.top()) {
                stck.pop();
            } else {
                stck.push(c);    
            }
        }
        
        string ans = "";
        while(!stck.empty()) {
            ans += stck.top();
            stck.pop();
        }
        
        reverse(ans.begin(), ans.end());
        return ans;
    }
};