class Solution {
public:
    map<int,int> memo;
    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
        int n = startTime.size();
        vector<vector<int>> jobs;
        
        for(int i = 0; i < n; i++) {
            jobs.push_back({startTime[i], endTime[i], profit[i]});
        }
        sort(jobs.begin(), jobs.end());
        
        vector<int> sortedStartTimes;
        for(int i = 0; i < n; i++) {
            sortedStartTimes.push_back(jobs[i][0]);
        }
        
        return dfs(jobs,sortedStartTimes, 0);
    }
    
    int dfs(vector<vector<int>>& jobs, vector<int>& sortedStartTimes, int i) {
        if(i == jobs.size()) return 0;
        
        if(memo.find(i) != memo.end())
            return memo[i];
        
        auto nextJobIdx = lower_bound(sortedStartTimes.begin(), sortedStartTimes.end(), jobs[i][1]) - sortedStartTimes.begin();
        
        int maxProfit = max(dfs(jobs, sortedStartTimes, i+1), jobs[i][2] + dfs(jobs, sortedStartTimes, nextJobIdx));
        
        memo[i] = maxProfit;
        
        return maxProfit;
    }
};

/*
either take current job or skip it
if take, need to find next available job you can take

optimize with binary search and sorting
*/