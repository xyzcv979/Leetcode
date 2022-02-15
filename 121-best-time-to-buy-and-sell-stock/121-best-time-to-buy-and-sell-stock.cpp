class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int maxProfit = 0;
        int maxVal = 0;
        for(int i = prices.size() - 1; i >= 0; i--){
            maxVal = max(prices[i], maxVal);
            int profit = maxVal - prices[i];
            maxProfit = max(maxProfit, profit);
        }
        return maxProfit;
    }
};