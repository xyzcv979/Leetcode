class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int maxP = 0;
        int minVal = INT_MAX;
        for(int i = 0; i < prices.size(); i++) {
            minVal = min(minVal, prices[i]);
            maxP = max(maxP, prices[i] - minVal);
        }
        
        return maxP;
    }
};