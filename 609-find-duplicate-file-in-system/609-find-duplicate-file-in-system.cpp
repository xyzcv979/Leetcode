class Solution {
public:
    vector<string> split(string path) {
        vector<string> ans;
        istringstream ss(path);
        string word;
        
        while(ss >> word) {
            ans.push_back(word);
        }
        return ans;
    }
    
    vector<vector<string>> findDuplicate(vector<string>& paths) {
        unordered_map<string, vector<string>> contentMap;
        
        for(string path : paths) {
            vector<string> splits = split(path);
            string dir = splits[0];
            for(int i = 1; i < splits.size(); i++) {
                string currText = splits[i];
                int left = 0, right = 0;
                while(currText[left] != '(')
                    left++;
                while(currText[right] != ')')
                    right++;
                
                string content = currText.substr(left, right-left);
                string currPath = dir + "/" + currText.substr(0, left);
                contentMap[content].push_back(currPath);
            }
        }
        
        vector<vector<string>> ans;
        for(auto it : contentMap) {
            if(it.second.size() > 1)
                ans.push_back(it.second);
        }
        return ans;
    }
};

/*
path: root/d1/d2...dm f1.text(f1_content), f2.text... fn.txt
m >= 0, m == 0 is root
n >= 1

output list of groups of duplicate file paths
each group has same file content


*/