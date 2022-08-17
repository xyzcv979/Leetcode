class Solution {
public:
    int uniqueMorseRepresentations(vector<string>& words) {
        vector<string> morseMapping = {
            ".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.."
        };
        unordered_set<string> transformations;
        
        for(string word : words) {
            string morse = "";
            for(char c : word) {
                morse += morseMapping[c - 'a'];
            }
            transformations.insert(morse);
        }
        
        return transformations.size();
    }
};