class Solution {
public:
    
    string reverseWords(string s) {
        stringstream ss(s);
        string word;
        stack<string> stck;
        while(ss >> word){
            stck.push(word);
            
        }
        
        string ret;
        int stckSize = stck.size();
        for(int i = 0; i < stckSize; i++){
            ret.append(stck.top());
            if(i != stckSize - 1)
                ret.append(" ");
            stck.pop();
        }
        return ret;
    }
};