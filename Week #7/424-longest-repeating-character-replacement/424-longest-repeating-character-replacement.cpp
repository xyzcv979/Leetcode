class Solution {
public:
    int characterReplacement(string s, int k) {
        // Given a string, what's the minimum times you can
        // flip a character so all characters the same?
        // Answer: string.size() - highest frequency of same letter
        // Apply this with k constraint:
        // substring.size() - highest freq <= k
        
        int n = s.size();
        int counts[26] {0};
        int left = 0, right = 0;
        int localMaxCount = 0;
        int ret = 0;
        for(; right < n; right++){
            int currLetter = s[right] - 'A';
            counts[currLetter]++;
            localMaxCount = max(localMaxCount, counts[currLetter]);
            while((right - left + 1) - localMaxCount > k){
                counts[s[left] - 'A']--;
                left++;
                for(int i = 0; i < 26; i++){
                    localMaxCount = max(localMaxCount, counts[i]);
                }
            }
            ret = max(ret, right - left + 1);
        }
        
        return ret;
    }
};