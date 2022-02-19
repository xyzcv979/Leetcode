class Solution {
public:
    bool isValid(string s) {
        stack<char> stck;
        for(char c : s){
            if(c == '(' || c == '[' || c == '{')
                stck.push(c);
            else if(stck.size() == 0)
                return false;
            else{
                if(c == ')' && stck.top() == '(')
                    stck.pop();
                else if(c == ']' && stck.top() == '[')
                    stck.pop();
                else if(c == '}' && stck.top() == '{')
                    stck.pop();
                else return false;
            }
        }
        return stck.size() == 0 ? true : false;
    }
};