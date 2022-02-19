class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int sum = 0;
        int leftPtr = 0;
        int minSize = INT_MAX;
        for(int i = 0; i < nums.size(); i++){
            sum += nums[i];
            while(sum >= target){
                minSize = min(minSize, i + 1- leftPtr);
                sum -= nums[leftPtr];
                leftPtr++;
            }
        }
        if(minSize == INT_MAX)
            return 0;
        return minSize;
    }
};