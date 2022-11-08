class Solution {
public:
    string makeGood(string s) {
        vector<char> stck;
        
        for(char c : s) {
            if(!stck.empty() && abs(stck.back() - c) == 32) {
                stck.pop_back();
            } else {
                stck.push_back(c);
            }
        }
        
        string ans(stck.begin(), stck.end());
        return ans;
    }
};