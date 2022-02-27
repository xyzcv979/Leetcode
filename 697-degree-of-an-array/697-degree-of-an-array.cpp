class Solution {
public:
    int findShortestSubArray(vector<int>& nums) {
        unordered_map<int, int> counts, firstIndex;
        int minLen = 0, degree = 0;
        for(int i = 0; i < nums.size(); i++){
            int currNum = nums[i];
            if(firstIndex.count(currNum) == 0)
                firstIndex[currNum] = i;
            counts[currNum]++;
            if(counts[currNum] > degree){
                degree = counts[currNum];
                minLen = i - firstIndex[currNum] + 1;
            }
            else if(counts[currNum] == degree)
                minLen = min(minLen, i - firstIndex[currNum] + 1);
        }
        return minLen;
    }
};