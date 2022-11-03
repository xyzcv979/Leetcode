class Solution {
public:
    int longestPalindrome(vector<string>& words) {
        map<string, int> wordMp;
        
        for(string s : words) {
            wordMp[s]++;
        }
        
        int len = 0;
        bool foundOdd = false;
        for(auto it : wordMp) {
            string curr = it.first;
            int copies = it.second;
            
            if(wordMp[curr] == 0)
                continue;

            // words are palindromes: aa aa aa
            if(curr[0] == curr[1]) {
                if(copies % 2 == 0) { // odd copies of palindrome, save one for later            
                    len += copies;
                } else {
                    len += copies - 1;
                    foundOdd = true;
                }

            } else {
                // or word + revWord
                string revCurr = curr;
                reverse(revCurr.begin(), revCurr.end());
                int revCopies = wordMp[revCurr];

                wordMp[revCurr] = 0;

                // ab ab,   ba
                int copiesToAdd = min(revCopies, copies);
                len += (copiesToAdd * 2);
            }         
        }
        
        if(foundOdd) {
            len++;
        }
        
        return len*2;
    }
};

/*
ab ba

list of palindromes

longest string = add all even sized palindromes
add 1 odd length


"ab","ty","yt","lc","cl","ab"

tylcclyt

*/