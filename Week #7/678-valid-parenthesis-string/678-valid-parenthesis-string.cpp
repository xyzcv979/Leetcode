class Solution {
public:
    bool checkValidString(string s) {
        int left = 0, right = 0;
        for(char ch : s){
            left += (ch == '(') ? 1 : -1;
            right += (ch != ')') ? 1 : -1;
            if(right < 0)
                break;
            left = max(left, 0);
        }
        return !left;
    }
};