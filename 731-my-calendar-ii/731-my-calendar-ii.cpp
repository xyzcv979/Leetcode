class MyCalendarTwo {
public:
    map<int,int> diffMap;
    MyCalendarTwo() {
        
    }
    
    bool book(int start, int end) {
        diffMap[start]++;
        diffMap[end]--;
        int maxBooked = 0;
        for(auto it : diffMap) {
            maxBooked += it.second;
            if(maxBooked >= 3) {
                diffMap[start]--;
                diffMap[end]++;
                if(diffMap[start] == 0) {
                    diffMap.erase(start);
                }
                return false;
            }
        }
        return true;
    }
};

/**
 * Your MyCalendarTwo object will be instantiated and called as such:
 * MyCalendarTwo* obj = new MyCalendarTwo();
 * bool param_1 = obj->book(start,end);
 */