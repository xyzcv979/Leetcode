class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_set<int> set;
        int leftPtr = 0, rightPtr = 0;
        int maxLen = 0;
        int n = s.size();
        while(leftPtr < n && rightPtr < n){
            char curr = s[rightPtr];
            if(set.find(curr) == set.end()){
                rightPtr++;
                maxLen = max(maxLen, rightPtr - leftPtr);
                set.insert(curr);
            }
            else{
                set.erase(s[leftPtr]);
                leftPtr++;
            }
        }
        return maxLen;
    }
};