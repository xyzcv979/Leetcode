class Solution {
public:
    map<int, int> memo;
    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
        int n = startTime.size();
        vector<vector<int>> jobs;
        vector<int> newStartTime(n);
        vector<int> dp(n,0);
        
        for(int i = 0; i < n; i++) {
            jobs.push_back({startTime[i], endTime[i], profit[i]});
        }
        
        sort(jobs.begin(), jobs.end());
        
        // Set sorted start times for binary search
        for(int i = 0; i < n; i++) {
            newStartTime[i] = jobs[i][0];
        }
        
        return findMaxProfit(jobs, newStartTime, n, 0);
    }
    
    int findMaxProfit(vector<vector<int>>& jobs, vector<int>& startTime, int n, int pos) {
        if(pos == n)
            return 0;
        
        if(memo.find(pos) != memo.end())
            return memo[pos];
        
        // Binary search: return iterator to first ele (startTime) which is >= than ele at jobs[pos][1] (job end time)
        auto nextValidItr = lower_bound(startTime.begin(), startTime.end(), jobs[pos][1]) - startTime.begin();
        
        // Take it or leave it
        // If you take current job, pass in next valid job idx which is done via binary search
        int maxProfit = max(findMaxProfit(jobs, startTime, n, pos+1), jobs[pos][2] + findMaxProfit(jobs, startTime, n, nextValidItr));

        memo[pos] = maxProfit;
        return maxProfit;
    }
};

/*
sort by start times first
dp: take it or leave it
binary search to optimize for searching for jobs that don't conflict with the job you picked
linear search would take too long
*/