class RandomizedSet {
public:
    map<int,int> mp;
    vector<int> array;
    RandomizedSet() {
        
    }
    
    bool insert(int val) {
        if(mp.find(val) != mp.end())
            return false;

        array.push_back(val);
        mp[val] = array.size()-1;
        return true;
    }
    
    // Remove value, pop last element out and insert into delete spot
    bool remove(int val) {
        // Not in map
        if(mp.find(val) == mp.end())
            return false;

        int oldIdx = mp[val];
        int temp = array[array.size()-1];
        array.pop_back();
        mp.erase(val);
        // Removed element is last element
        if(val == temp)
            return true;
        
        array[oldIdx] = temp;
        mp[temp] = oldIdx;
        return true;
    }
    
    int getRandom() {
        return array[rand()%array.size()];
    }
};

/*
randomized:
can't index set
if i can index an array, i can have a randomized index

can't implement as array because need to delete in O(1) time

map + array

*/

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */