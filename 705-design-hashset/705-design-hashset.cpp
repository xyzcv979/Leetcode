class MyHashSet {
public:
    int PRIME_NUMBER;
    vector<vector<int>> table;
    
    MyHashSet() {
        PRIME_NUMBER = 17;
        vector<vector<int>> init(PRIME_NUMBER);
        table = init;
    }
    
    void add(int key) {
        int index = key % 17;
        if(!contains(key)) table[index].push_back(key);
    }
    
    void remove(int key) {
        int index = key % 17;
        if(contains(key)){
            for(int i = 0; i < table[index].size(); i++){
                if(table[index][i] == key) {
                    table[index].erase(table[index].begin() + i);
                    return;
                }
            }
        }
    }
    
    bool contains(int key) {
        int index = key % 17;
        vector<int>::iterator iter = find(table[index].begin(), table[index].end(), key);
        if(iter != table[index].end()) return true;
        else return false;
    }
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */