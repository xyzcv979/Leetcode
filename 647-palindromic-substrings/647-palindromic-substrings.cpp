class Solution {
    bool isPalindrome(const string& s, int lo, int hi) {
        while (lo < hi) {
            if (s[lo] != s[hi])
                return false;

            ++lo;
            --hi;
        }

        return true;
    }

 public:
    int countSubstrings(string s) {
        int ans = 0;

        for (int lo = 0; lo < s.size(); ++lo)
            for (int hi = lo; hi < s.size(); ++hi)
                ans += isPalindrome(s, lo, hi);

        return ans;
    }
};