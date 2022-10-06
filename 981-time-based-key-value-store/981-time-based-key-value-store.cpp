class TimeMap {
public:
    unordered_map<string, vector<pair<string, int>>> keyTimestamp;
    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) {
        keyTimestamp[key].push_back({value, timestamp});
    }
    
    string get(string key, int timestamp) {
        string prev = "";

        prev = binarySearch(keyTimestamp[key], timestamp);
        
        return prev;
    }
    
    string binarySearch(vector<pair<string, int>>& pairs, int timestamp) {
        int left = 0, right = pairs.size();
        
        while(left < right) {
            int mid = left + (right - left) / 2;
            int midTime = pairs[mid].second;
            
            if(midTime <= timestamp) {
                left = mid + 1;
            } else {
                right = mid;
            }
        }
        
        if(left-1 < 0 || left-1 >= pairs.size())
            return "";
        return pairs[left-1].first;
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