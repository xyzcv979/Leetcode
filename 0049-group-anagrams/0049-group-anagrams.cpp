class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> anagrams;
        
        for(string s : strs) {
            string t = s;
            sort(t.begin(), t.end());
            anagrams[t].push_back(s);
        }
        
        vector<vector<string>> ans;
        for(auto it : anagrams) {
            ans.push_back(it.second);
        }
        return ans;
    }
};

/*
store anagrams in a hashmap



*/