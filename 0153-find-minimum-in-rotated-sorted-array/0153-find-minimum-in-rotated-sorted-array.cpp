class Solution {
public:
    int findMin(vector<int>& nums) {
         if(nums.size() < 2) {
             return nums[0];
         }
        // Binary search
        int left = 0, right = nums.size() - 1;
        int minVal = INT_MAX;
        
        while(left < right){
            int mid = left + (right - left) / 2;
            int numMid = nums[mid], numLeft = nums[left], numRight = nums[right];
            
            if(numMid > numRight) {
                left = mid + 1;
            } else {
                right = mid;
            }
            
        }
        return nums[left];
    }
};