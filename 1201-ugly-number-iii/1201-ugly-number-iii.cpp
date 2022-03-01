class Solution {
public:
    long long lcm(long long a, long long b){
        return a / __gcd(a,b) * b;
    }
    long long count(long long x, long long a, long long b, long long c){
        return x/a + x/b + x/c - x/lcm(a,b) - x/lcm(a,c) - x/lcm(b,c) + x/lcm(a,lcm(b,c));
    }
    int nthUglyNumber(int n, int a, int b, int c) {
        int low = 1, high = INT_MAX;
        while(low<high){
            int mid = low+(high - low)/2;
            if(count(mid, a, b, c) >= n)
                high = mid;
            else
                low = mid+1;
        }
        return low;
    }
};