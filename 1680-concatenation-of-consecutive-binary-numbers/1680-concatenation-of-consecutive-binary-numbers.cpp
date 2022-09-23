class Solution {
public:
    int mod = 1e9+7;
    int concatenatedBinary(int n) {
        long val = 0;
        
        for(int i = 1; i <= n; i++) {
            int numOfBits = (int)log2(i) + 1;
            val <<= numOfBits;
            val |= i;
            
            val %= mod;
        }
        return val%mod;
    }
};

/*
n = 3
27

1  2   3 
1  10  11

n = 2
6

1 << num of bits
100 | n
110

num of bits = log(n) + 1
*/