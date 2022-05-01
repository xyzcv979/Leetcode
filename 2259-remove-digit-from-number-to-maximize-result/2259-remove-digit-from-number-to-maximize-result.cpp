class Solution {
public:
    string removeDigit(string number, char digit) {
        int n = number.size();
        string maxStr = "";
        for(int i = 0; i < n; i++){
            if(number[i] == digit){
                string curr = "";
                curr += number.substr(0, i);
                curr += number.substr(i+1, n);
                if(curr > maxStr) maxStr = curr;
            } 
        }
        return maxStr;
    }
};