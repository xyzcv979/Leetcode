class Solution {
public:
    bool sumOfNumberAndReverse(int num) {
        for(int i = 0; i <= num; i++) {
            if(i + reverseNum(i) == num)
                return true;
        }
        return false;
    }
    
    int reverseNum(int n) {
        int ans = 0;
        while (n >= 1) {
            ans = 10 * ans + (n%10);
            n = n/10;
        }
        
        return ans;

    }
};