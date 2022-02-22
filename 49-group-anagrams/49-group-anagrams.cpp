class Solution {
public:
    string countSort(string s){
        int count[26] = {0};
        for(char c : s)
            count[c - 'a']++;
        string t = s;
        int indexT = 0;
        for(int i = 0; i < 26; i++){
            while(count[i] > 0){
                t[indexT++] = i + 'a';
                count[i]--;
            }
        }
            
        return t;
    }
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        if(strs.size() < 2)
            return vector<vector<string>>{strs};
        
        vector<vector<string>> ans;
        unordered_map<string, vector<string>> hashMap;
        for(string s : strs){
            hashMap[countSort(s)].push_back(s);
        }
        
        for(auto strs : hashMap){
            ans.push_back(strs.second);
        }
        return ans;
    }
};