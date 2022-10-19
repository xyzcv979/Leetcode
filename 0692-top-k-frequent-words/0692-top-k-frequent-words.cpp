class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        unordered_map<string, int> wordFreq;
        
        // map string to count ie. "love" : 2
        for(string word : words) {
            wordFreq[word]++;
        }
        
        // Add as a pair of int string to a vector
        vector<pair<int, string>> countToWords;
        for(auto it : wordFreq) {
            countToWords.push_back({it.second, it.first});
        }
        
        // Custom sort in descending order
        // Check if strings are equal, if so, return lexicographical smaller one
        // Else order by the count of the strings
        sort(countToWords.begin(), countToWords.end(), [](auto &a, auto &b) {
            if(a.first == b.first)
                return a.second < b.second;
            else
                return b.first < a.first;
        });
        
        // Get top k strings
        vector<string> ans;
        int i = 0;
        while(k) {
            ans.push_back(countToWords[i].second);
            i++;
            k--;
        }
        
        return ans;
    }
};