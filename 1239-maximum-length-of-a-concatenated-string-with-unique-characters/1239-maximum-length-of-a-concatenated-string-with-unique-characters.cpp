class Solution {
public:
    int maxLength(vector<string>& arr) {
        vector<string> validStrings = {""};
        int best = 0;
        
        for(string s : arr) {
            int arrSize = validStrings.size();
            for(int i = 0; i < arrSize; i++) {
                string concatWords = validStrings[i] + s;
                unordered_set<char> findDups(concatWords.begin(), concatWords.end());
                if(concatWords.size() != findDups.size()) {
                    continue;
                }
                validStrings.push_back(concatWords);
                best = max(best, (int)concatWords.size());
            }

        }
        return best;
    }
};