class TimeMap {
public:
    unordered_map<string, map<int, string>> keyTimestamp;
    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) {
        keyTimestamp[key][timestamp] = value;
    }
    
    string get(string key, int timestamp) {
        if(keyTimestamp.find(key) == keyTimestamp.end()) {
            return "";
        }
        
        auto it = keyTimestamp[key].upper_bound(timestamp);
        if(it == keyTimestamp[key].begin()) {
            return "";
        }
        
        return prev(it)->second;
    }
    
   
};
/*
timestamp_prev <= timestamp


save timestamp state

key : value1, value2, (determined by timestamp)

binary search to optimize finding previous timestamp?


foo bar 1
foo 1
foo 3

foo bar2 4
foo 4
foo 5

*/


/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */