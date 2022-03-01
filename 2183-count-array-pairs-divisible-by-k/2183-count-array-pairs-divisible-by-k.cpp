class Solution {
public:
    long long countPairs(vector<int>& nums, int k) {
        // Count GCDs
        long long ret = 0;
        unordered_map<int, int> gcds;
        for(int n : nums){
            long long currGcd = gcd(n, k);
            for(auto [key, val] : gcds){ // run through prev gcds so far
                ret += currGcd * key % k ? 0 : val;    
            }  
            gcds[currGcd]++;
            
        }
        return ret;
    }
};