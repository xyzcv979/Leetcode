class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char, int> freq;
        string ans;
        auto comp = [&freq](char c1, char c2) {
            return freq[c1] < freq[c2];
        };
        priority_queue<char, vector<char>, decltype(comp)> pq(comp);
        
        for(char c : s) {
            freq[c]++;
        }
        
        for(auto it : freq) {
            pq.push(it.first);
        }
        
        while(!pq.empty()) {
            char c = pq.top();
            for(int i = 0; i < freq[c]; i++) {
                ans += c;
            }
            pq.pop();
        }
        return ans;
    }
};