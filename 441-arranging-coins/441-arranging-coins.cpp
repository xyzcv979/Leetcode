class Solution {
public:
    int arrangeCoins(int n) {
        long left = 0, right = n;
        long k, curr;
        while(left <= right){
            k = left + (right - left) / 2;
            curr = k * (k + 1) / 2;
            if(curr == n)
                return (int) k;
            if(curr < n)
                left = k + 1;
            else
                right = k - 1;
        }
        return (int) right;
    }
};