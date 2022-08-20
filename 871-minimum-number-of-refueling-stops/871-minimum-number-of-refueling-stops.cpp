class Solution {
public:
    int minRefuelStops(int target, int startFuel, vector<vector<int>>& stations) {
        priority_queue<int> pq;
        int count = 0, stationIdx = 0;
        int n = stations.size();
        
        while(startFuel < target) {
            while(stationIdx < n && stations[stationIdx][0] <= startFuel) { 
                pq.push(stations[stationIdx][1]); // store fuel count for later
                stationIdx++;
            }
            
            if(pq.empty()) return -1;
            
            startFuel += pq.top();
            pq.pop();
            count++;
        }
        
        return count;
    }
};

/*
start - - station[i] = {pos, fuel} - - - target
startFuel
1L gas per 1 mile
can stop at station to refuel, add all fuel to startFuel

return min # of refueling stops to reach target
else return -1

arriving with 0 fuel = still can refuel/reached target

*/