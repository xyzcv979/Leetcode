class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int left = 0, right = 0;
        int maxWinLen = 0;
        int n = nums.size();
        int zeroCount = 0;
        
        while(right < n) {
            int num = nums[right];
            
            if(num == 0) {
                zeroCount++;
            }
            
            while(zeroCount > 1) {
                if(nums[left] == 0) {
                    zeroCount--;
                }
                left++;
            }
            
            maxWinLen = max(maxWinLen, right-left+1);
            right++;
        }
        
        return maxWinLen;
    }
};