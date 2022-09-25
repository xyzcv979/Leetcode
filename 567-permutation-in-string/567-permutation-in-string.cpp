class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int sz = s1.size();
        int left = 0;
        vector<int> counts(26);
        
        for(char c : s1)
            counts[c-'a']++;
        
            
        while(left < s2.size()) {
            
            if(isPermutation(counts, s1, s2.substr(left, sz)))
                return true;
            
            left++;
        }
        
        return false;
    }
    
    bool isPermutation(vector<int> counts, string s1, string s2) {
        for(char c: s2)
            counts[c-'a']--;
        for(int i : counts) {
            if(i != 0)
                return false;
        }
        
        return true;
    }
};

/*
generate permutations
put in hashset


sliding window of s1 size and check w/ hashset
actually don't need permutations.
just check if curr window has all chars in s1
like sort but that is too costly

*/