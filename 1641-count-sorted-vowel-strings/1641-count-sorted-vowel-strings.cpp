class Solution {
public:
    
    int backtrack(int n, int vowels){
        if(n == 0) return 1;
        
        int result = 0;
        for(int i = vowels; i <= 5; i++)
            result += backtrack(n-1, i);
        return result;
        
    }
    int countVowelStrings(int n) {
        return backtrack(n, 1);
    }
};