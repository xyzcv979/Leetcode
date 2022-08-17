class TrieNode {
public:
    TrieNode* children[26];
    bool isComplete;
    TrieNode() {
        isComplete = false;
        for(int i = 0; i < 26; i++)
            children[i] = NULL;
    }
};
class Trie {
private:
    TrieNode* root;
public:

    Trie() {
        root = new TrieNode();
    }
    
    void insert(string word) {
        TrieNode* cur = root;
        int idx = 0;
        for(char c : word) {
            idx = c - 'a';
            if(cur->children[idx] == NULL) {
                cur->children[idx] = new TrieNode();
            }
            cur = cur->children[idx];
        }
        cur->isComplete = true;
    }
    
    bool search(string word) {
        TrieNode* cur = root;
        int idx = 0;
        for(char c : word) {
            idx = c - 'a';
            if(cur->children[idx] == NULL) return false;
            cur = cur->children[idx];
        }
        return cur->isComplete;
    }
    
    bool startsWith(string prefix) {
        TrieNode* cur = root;
        int idx = 0;
        for(char c : prefix) {
            idx = c - 'a';
            if(cur->children[idx] == NULL) return false;
            cur = cur->children[idx];
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */