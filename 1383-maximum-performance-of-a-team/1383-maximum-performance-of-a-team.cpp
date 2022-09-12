class Solution {
public:
    int MOD = 1e9 + 7;
    int maxPerformance(int n, vector<int>& speed, vector<int>& efficiency, int k) {
        vector<pair<int,int>> effSpeed;
        priority_queue<int, vector<int>, greater<int>> speedMinHeap;
        
        for(int i = 0; i < n; i++) {
            effSpeed.push_back({efficiency[i], speed[i]});
        }
        sort(effSpeed.rbegin(), effSpeed.rend());
        
        long sumSpeed = 0, ans = 0;
        for(int i = 0; i < n; i++) {
            int currSpeed = effSpeed[i].second;
            int currEff = effSpeed[i].first;
            
            if(speedMinHeap.size() == k) {
                sumSpeed -= speedMinHeap.top();
                speedMinHeap.pop();
            }
            
            sumSpeed += currSpeed;
            speedMinHeap.push(currSpeed);
            
            ans = max(ans, sumSpeed * currEff);
        }
        
        return ans % MOD;
    }
};

/*
sort by efficiency decreasing
for every efficiency, you get k speeds in a minHeap, popping out minimum speed
get the max of these performances

*/