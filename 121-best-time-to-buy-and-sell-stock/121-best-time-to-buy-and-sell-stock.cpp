class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int maxProfit = 0;
        int minVal = INT_MAX;
        for(int i : prices){
            int localProfit = 0;
            if(i > minVal){
                localProfit = i - minVal;
            }
            else{
                minVal = min(minVal, i);
            }
            maxProfit = max(localProfit, maxProfit);
        }
        return maxProfit;
    }
};