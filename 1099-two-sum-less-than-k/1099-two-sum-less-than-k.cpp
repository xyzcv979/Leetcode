class Solution {
public:
    int twoSumLessThanK(vector<int>& nums, int k) {
        int left = 0, right = nums.size()-1;
        int maxPossSum = -1;
        
        sort(nums.begin(), nums.end());
        
        while(left < right) {
            if(nums[right] + nums[left] >= k) {
                right--;
            } else {
                maxPossSum = max(maxPossSum, nums[right]+nums[left]); 
                left++;
            }
        }
        return maxPossSum;
    }
};