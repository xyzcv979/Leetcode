class Solution {
public:
    int balancedStringSplit(string s) {
        int count = 0;
        int balanced = 0;
        for(int i = 0; i < s.size(); i++){
            if(s[i] == 'R')
                balanced++;
            else
                balanced--;
            if(balanced == 0)
                count++;
        }
        return count;
    }
};