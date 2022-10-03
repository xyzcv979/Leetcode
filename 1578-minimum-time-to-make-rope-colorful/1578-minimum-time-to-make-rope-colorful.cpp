class Solution {
public:
    int minCost(string colors, vector<int>& neededTime) {
        int minTime = 0;
        int left = 0;
        while(left < colors.size()) {
            int right = left + 1;
            
            priority_queue<int, vector<int>, greater<int>> minHeap;
            minHeap.push(neededTime[left]);
            while(right < colors.size() && colors[right] == colors[left]) {
                minHeap.push(neededTime[right]);
                right++;
            }
            while(minHeap.size() > 1) {
                minTime += minHeap.top();
                minHeap.pop();
            }
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