class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int maxSum = nums[0];
        int localSum = nums[0];
        for(int i = 1; i < nums.size(); i++){
            localSum = max(nums[i] + localSum, nums[i]);
            maxSum = max(maxSum, localSum);
        }
        return maxSum;
    }
};