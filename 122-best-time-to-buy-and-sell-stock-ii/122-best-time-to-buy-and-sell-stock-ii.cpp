class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size()-1, idx = 0, sell = 0, buy = 0, maxProf = 0;
        
        while(idx < n) {
            while(idx < n && prices[idx] >= prices[idx+1])
                idx++;
            
            buy = prices[idx];
            
            while(idx < n && prices[idx] < prices[idx+1])
                idx++;
            
            sell = prices[idx];
            
            maxProf += sell - buy;
        }
        return maxProf;
    }
};