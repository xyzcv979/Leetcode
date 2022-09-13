class HitCounter {
public:
    map<int, int> hitMap;
    HitCounter() {
        
    }
    
    void hit(int timestamp) {
        hitMap[timestamp]++;
    }
    
    int getHits(int timestamp) {
        int startTime = timestamp - 300;
        
        int hits = 0;
        for(int i = startTime+1; i <= timestamp; i++) {
            if(hitMap.count(i) > 0)
                hits += hitMap[i];
        }
        return hits;
    }
};

/**
 * Your HitCounter object will be instantiated and called as such:
 * HitCounter* obj = new HitCounter();
 * obj->hit(timestamp);
 * int param_2 = obj->getHits(timestamp);
 */