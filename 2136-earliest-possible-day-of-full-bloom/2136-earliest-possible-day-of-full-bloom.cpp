class Solution {
public:
    int earliestFullBloom(vector<int>& plantTime, vector<int>& growTime) {
        int n = plantTime.size();
        vector<pair<int,int>> seedGrowTime;
        
        for(int i = 0; i < growTime.size(); i++) {
            seedGrowTime.push_back({i, growTime[i]});
        }
        
        // Sort by grow time, keep track of index
        sort(seedGrowTime.begin(), seedGrowTime.end(), [](auto& a, auto&b) {
           return  a.second > b.second;
        });
        
        
        int prefixSum = 0;
        int maxSeedBloom = 0;
        for(auto it : seedGrowTime) {
            int idx = it.first;
            prefixSum += plantTime[idx];
            maxSeedBloom = max(maxSeedBloom, prefixSum + growTime[idx]);
        }
        

        return maxSeedBloom;
    }
};
/*
you can only plant seed after planting previous
seed starts growing in plant[i] time, blooms plant[i+1] time
can't be planting multiple seeds on one day, so can split them up in a row

bloom time of current seed = preceding sum plant time +  growtime 

*/