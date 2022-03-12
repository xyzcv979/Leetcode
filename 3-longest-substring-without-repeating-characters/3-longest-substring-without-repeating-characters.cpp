class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int length = 0;
        unordered_set<char> hashSet;
        int first = 0, second = 0;
        while(first < s.size() && second < s.size()){
            char curr = s[second];
            if(hashSet.count(curr) > 0){
                hashSet.erase(s[first]);
                first++;
            }
            else{
                hashSet.insert(curr);
                second++;
                length = max(length, second - first);
                
            }
            
        }
        return length;
    }
};