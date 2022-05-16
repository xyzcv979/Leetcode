class Solution {
public:
    string addStrings(string a, string b) {
        string res = "";
        int carry = 0;
        int i = a.size() - 1, j = b.size() - 1;
        while(i >= 0 || j >= 0){
            int aNum = (i >= 0 ? a[i] - '0': 0);
            int bNum = (j >= 0 ? b[j] - '0': 0);
            int currVal = aNum + bNum + carry;

            res += to_string(currVal % 10);
            carry = currVal / 10;

            i--;
            j--;
        }
        if(carry) res += to_string(carry);
        reverse(res.begin(), res.end());
        return res;
    }
};