class Solution {
public:
    int MOD = 1e9+7;
    int maxPerformance(int n, vector<int>& speed, vector<int>& efficiency, int k) {
        priority_queue<int, vector<int>, greater<int>> minSpeeds;
        vector<pair<int,int>> efficiencySpeed;
        long sumSpeeds = 0, ans = 0;
        
        for(int i = 0; i < n; i++) {
            efficiencySpeed.push_back({efficiency[i], speed[i]});
        }
        
        sort(efficiencySpeed.rbegin(), efficiencySpeed.rend());
        
        for(int i = 0; i < n; i++) {
            int currSpeed = efficiencySpeed[i].second;
            int currEff = efficiencySpeed[i].first;
            
            if(minSpeeds.size() == k) {
                sumSpeeds -= minSpeeds.top();
                minSpeeds.pop();
                
            }
            sumSpeeds += currSpeed;
            minSpeeds.push(currSpeed);
            ans = max(ans, sumSpeeds * currEff);
        }
        
        return ans % MOD;
    }
};

/*
choose k engineers with maximum performance
performance = sum(speeds) * min(efficiencys)


fix the lowest efficiency first
sort effeciency in decreasing order
for every effeciency, we now this is minimum at the time cause of the sortedness, 
keep a minHeap of speeds, whenever heap is == k size, pop out the loweset speed
*/