class Solution {
public:
    string orderlyQueue(string s, int k) {
        if(k == 1) {
            string ans = s;
            s += s;
            for (int i = 1; i < size(ans); ++i)
                ans = min(ans, s.substr(i, ans.size()));

            return ans;
        }
        sort(s.begin(), s.end());
        return s;
    }
};

/*
move any first k chars
do this as many times as possible

lexicographically smallest

out of the k elements, pick largest to push to back

baa ca
aac ab
aaa bc

*/