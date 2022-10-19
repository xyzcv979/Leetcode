class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        unordered_map<string, int> wordFreq;
        
        // love : 2
        for(string word : words) {
            wordFreq[word]++;
        }
        
        // 2 : i, love
        vector<pair<int, string>> countToWords;
        for(auto it : wordFreq) {
            countToWords.push_back({it.second, it.first});
        }
        sort(countToWords.begin(), countToWords.end(), [](auto &a, auto &b) {
            if(a.first == b.first)
                return a.second < b.second;
            else
                return b.first < a.first;
        });
        
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