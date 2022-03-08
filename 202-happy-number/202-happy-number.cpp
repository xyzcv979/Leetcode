class Solution {
public:
    int happify(int n){
        int ret = 0;
        while(n){
            int remain = n % 10;
            n /= 10;
            ret += remain * remain;
        }
        return ret;
    }
    bool isHappy(int n) {
        int firstPtr = n;
        int secondPtr = happify(n);
        while(secondPtr != 1){
            if(firstPtr == secondPtr)
                return false;
            firstPtr = happify(firstPtr);
            secondPtr = happify(happify(secondPtr));
        }
        return secondPtr == 1;
    }
};