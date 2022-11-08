class Solution {
public:
    string makeGood(string s) {
        string ans = "";
        stack<char> stck;
        
        for(char c : s) {
            if(stck.size() != 0) {
                char top = stck.top();
                if((isupper(top) && tolower(top) == c) || (isupper(c) && tolower(c) == top))
                    stck.pop();
                else
                    stck.push(c);
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