class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        if(strs.size() < 2)
            return vector<vector<string>>{strs};
        
        vector<vector<string>> ans;
        unordered_map<string, vector<string>> hashMap;
        for(string s : strs){
            string t = s;
            sort(t.begin(), t.end());
            hashMap[t].push_back(s);
        }
        
        for(auto strs : hashMap){
            ans.push_back(strs.second);
        }
        return ans;
    }
};