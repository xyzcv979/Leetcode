class Solution {
public:
    int minCost(string colors, vector<int>& neededTime) {
        int minTime = 0;
        int left = 0, right = 0;
        while(left < colors.size()) {
            int currTotal = 0, currMax = 0;
            while(right < colors.size() && colors[right] == colors[left]) {
                currTotal += neededTime[right];
                currMax = max(currMax, neededTime[right]);
                right++;
            }
            
            minTime += currTotal - currMax;
            left = right;
        }    
        
        return minTime;
    }
};

/*
greedy?

loop thru colors
loop thru consecutive colors
   add least neededTimes until consec color len = 1
   
   
*/