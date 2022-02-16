class Solution {
public:
    double myPow(double x, int n) {
        double ret = 1;
        long long pow = n;
        if(n < 0){
            x = 1 / x;
            pow = -pow;
        }
        
        while(pow){
            if(pow & 1)
                ret *= x;
            x *= x;
            pow >>= 1;
        }
        return ret;
    }
};