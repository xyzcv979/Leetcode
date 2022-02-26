class Solution {
public:
    int search(vector<int>& nums, int target) {
        int left = 0, right = nums.size() -1;
        while(left <= right){
            int mid = left + (right - left) / 2;
            if(nums[mid] == target)
                return mid;
            else if(nums[mid] < target){
                if(nums[left] > nums[mid] && target > nums[right]) // if in  reversed subarray
                    right = mid - 1;
                else
                    left = mid + 1;
            }
            else{ // nums[mid] > target
                if(nums[mid] > nums[right] && target < nums[left]) 
                    left = mid + 1;
                else
                    right = mid - 1;
            }
        }
        return -1;
    }
};