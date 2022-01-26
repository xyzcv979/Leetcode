class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string ret = "";
        for(int firstPtr = 0; firstPtr < strs[0].size(); firstPtr++){
            for(int wordPtr = 1; wordPtr <strs.size(); wordPtr++){
                if(strs[wordPtr][firstPtr] != strs[0][firstPtr])
                    return ret;
            }
            ret += strs[0][firstPtr]; 
        }
        return ret;
    }
};