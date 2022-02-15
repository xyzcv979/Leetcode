class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int maxProfit = 0;
        int maxVal = 0;
        for(int i = prices.size() - 1; i >= 0; i--){
            if(prices[i] > maxVal)
                maxVal = prices[i];
            else
                maxProfit = max(maxProfit, maxVal - prices[i]);
        }
        return maxProfit;
    }
};