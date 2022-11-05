struct TrieNode {
    TrieNode* children[26] = {};
    string* word;
    void addWord(string& word) {
        TrieNode* cur = this;
        for (char c : word) {
            c -= 'a';
            if (cur->children[c] == nullptr) cur->children[c] = new TrieNode();
            cur = cur->children[c];
        }
        cur->word = &word;
    }
};

class Solution {
public:
    int DIR[5] = {0, 1, 0, -1, 0};

    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        TrieNode trieNode;
        vector<string> ans;
        
        for (string& word : words) trieNode.addWord(word);
        
        for(int i = 0; i < board.size(); i++) {
            for(int j = 0; j < board[0].size(); j++) {
                dfs(board,ans,&trieNode,i,j);
            }
        }
        return ans;
    }
    
    void dfs(vector<vector<char>>& board, vector<string>& ans, TrieNode* curr, int r, int c) {
        if (r < 0 || r == board.size() || c < 0 || c == board[0].size() || board[r][c] == '#' || curr->children[board[r][c]-'a'] == nullptr) return;
        
        char curChar = board[r][c];
        curr = curr->children[curChar - 'a'];
        
        if (curr->word != nullptr) {
            ans.push_back(*curr->word);
            curr->word = nullptr; // Avoid duplication!
        }
        
        board[r][c] = '#'; // mark as visited!
        for (int i = 0; i < 4; ++i) dfs(board, ans, curr, r + DIR[i], c + DIR[i+1]);
        board[r][c] = curChar; // restore org state
    }
};