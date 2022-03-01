class Solution {
public:
    string repeatLimitedString(string s, int repeatLimit) {
        // sort from z to a
        // keep k characters
        // if reach k, swap with another character
       
        map<char, int> counts;
        for(char c : s){
            counts[c]++;
        }
        
        int cur = 0;
        string ret;
        for(int i = 0; i < s.size(); i++){
            for(char ch = 'z'; ch >= 'a'; ch--){
                if(!counts[ch])
                    continue;
                if(ret.empty() || ret.back() != ch){
                    cur = 1;
                    counts[ch]--;
                    ret += ch;
                    break;
                }
                else if(cur +1 <= repeatLimit){
                    cur++;
                    counts[ch]--;
                    ret += ch;
                    break;
                }
            }
        }
        return ret;
    }
};