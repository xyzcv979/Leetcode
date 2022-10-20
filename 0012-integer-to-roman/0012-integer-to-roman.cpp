class Solution {
public:

    
    string intToRoman(int num) {
        string ans = "";
        vector<int> romanInt = {1, 4, 5, 9, 10, 40, 50, 90, 100, 400, 500, 900, 1000};
        vector<string> romanString = {"I", "IV", "V", "IX", "X", "XL", "L", "XC", "C", "CD", "D", "CM", "M"};


       for(int i = romanInt.size()-1; i>=0; i--) {
           while(num >= romanInt[i]) {
               num -= romanInt[i];
               ans += romanString[i];
           }
       }
        
        return ans;
    }
};
/*
1 5 10 50 100 500 1000
4 9 40 90 400 900


*/