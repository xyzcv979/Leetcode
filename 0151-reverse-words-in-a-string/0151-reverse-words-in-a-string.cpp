class Solution {
public:    
    string reverseWords(string s) {
        stringstream ss(s);
        string word;
        vector<string> arr;
        
        while(ss >> word) {
            arr.push_back(word);
        }
        reverse(arr.begin(), arr.end());
        
        string ans = "";
        for(string s : arr) {
            ans += s + " ";
        }
        
        return ans.substr(0, ans.size()-1);
    }
};