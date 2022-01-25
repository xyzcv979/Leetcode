// Ref: https://leetcode.com/problems/add-binary/discuss/1679423/Well-Detailed-Explaination-Java-C%2B%2B-Python-oror-Easy-for-mind-to-Accept-it

class Solution {
public:
    string addBinary(string a, string b) {
        string result;
        int aIndex = a.length() - 1;
        int bIndex = b.length() - 1;
        int carry = 0;
        while(aIndex >= 0 || bIndex >= 0){
            int sum = carry;
            if(aIndex >= 0) sum += a[aIndex--] - '0'; 
            if(bIndex >= 0) sum += b[bIndex--] - '0'; 
            carry = sum > 1 ? 1 : 0;
            result = to_string(sum % 2) + result;
        }
        if(carry == 1) result = to_string(carry) + result;
        return result;
    }
};