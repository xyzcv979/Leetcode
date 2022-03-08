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
        unordered_set<int> seen;
        while(n != 1){
            if(seen.count(n) > 0)
                break;
            seen.insert(n);
            n = happify(n);
        }
        return (n == 1);
    }
};