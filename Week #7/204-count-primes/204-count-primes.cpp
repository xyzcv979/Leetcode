class Solution {
public:
    int countPrimes(int n) {
        vector<bool> flag(int(1e7), true);
        flag[0] = flag[1] = false;
        for(int i = 2; i < sqrt(n); i++){
            if(flag[i])
                for(int j = i; j*i<n; j++){
                    flag[j*i] = false;
                }
        }
        int ret = 0;
        for(int i = 0; i < n; i++){
            if(flag[i])
                ret++;
        }
        return ret;
    }
};