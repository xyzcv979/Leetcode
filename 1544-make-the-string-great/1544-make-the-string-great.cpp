class Solution {
public:
    string makeGood(string s) {
        string ans = "";
        stack<char> stck;
        
        for(char c : s) {
            if(!stck.empty() && abs(stck.top() - c) == 32) {
                stck.pop();
            } else {
                stck.push(c);
            }
        }
        
        while(stck.size()) {
            ans += stck.top();
            stck.pop();
        }
        
        reverse(ans.begin(), ans.end());
        return ans;
    }
};