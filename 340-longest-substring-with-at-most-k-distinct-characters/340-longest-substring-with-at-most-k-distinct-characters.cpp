class Solution {
public:
    int lengthOfLongestSubstringKDistinct(string s, int k) {
        map<char, int> freqTable;
        int leftPtr = 0;
        int rightPtr = 0;
        int maxLen = 0;
        for(; rightPtr < s.size(); rightPtr++){
            freqTable[s[rightPtr]]++;
            if(freqTable.size() > k){
                maxLen = max(maxLen, rightPtr - leftPtr);
                while(freqTable.size() > k){    
                    freqTable[s[leftPtr]]--;        
                    if(freqTable[s[leftPtr]] == 0)
                        freqTable.erase(s[leftPtr]);
                    leftPtr++; 
                }
            }
        }
        return max(maxLen, rightPtr - leftPtr);
        
    }
};