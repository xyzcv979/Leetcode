class TimeMap {
public:
    unordered_map<string, vector<pair<string, int>>> kvTime;
    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) {
        kvTime[key].push_back({value, timestamp});
    }
    
    string get(string key, int timestamp) {
        if (kvTime.find(key) == kvTime.end()) {
            return "";
        }
        
        int left = 0, right = kvTime[key].size() - 1;
        
        while(left <= right) {
            int mid = left + (right - left) / 2;
            
            if(kvTime[key][mid].second == timestamp){
                return kvTime[key][mid].first;
            } else if(kvTime[key][mid].second < timestamp) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
        
        if(right >= 0) {
            return kvTime[key][right].first;
        }
        return "";
    }
};

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */