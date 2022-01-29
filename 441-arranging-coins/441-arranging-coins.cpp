class Solution {
public:
    int arrangeCoins(int n) {
        int ret = 1;
        while(n > 0){
            ret++;
            n -= ret;
        }
        return ret - 1;
    }
};