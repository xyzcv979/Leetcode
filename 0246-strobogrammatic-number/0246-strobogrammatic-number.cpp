class Solution {
public:
    bool isStrobogrammatic(string num) {
        unordered_set<int> st {
          0,1,6,8,9  
        };
        
        string revNum = num;
        reverse(revNum.begin(), revNum.end());
        
        for(int i = 0; i < revNum.size(); i++) {
            if(st.find(revNum[i] - '0') == st.end()) {
                return false;
            }
            if(revNum[i] == '6') {
                revNum[i] = '9';
            } else if(revNum[i] == '9') {
                revNum[i] = '6';
            }
        }
        
        return revNum == num;
    }
};

/*
only happens with 6,8,9,10
*/