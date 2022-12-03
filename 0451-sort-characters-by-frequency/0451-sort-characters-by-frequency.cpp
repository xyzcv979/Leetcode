class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char, int> freq;
        
        for(char c : s) {
            freq[c]++;
        }
        
        map<int, vector<char>> countToChar;
        for(auto it : freq) {
            countToChar[it.second].push_back(it.first);
        }
        
        string ans;
        for(auto it : countToChar) {
            for(char c : it.second) {
                for(int i = 0; i < it.first; i++) {
                    ans.push_back(c);
                }
                
            }
        }
        
        reverse(ans.begin(), ans.end());
        return ans;
    }
};