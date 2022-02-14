class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int left = 0, count = 0;
        for(int i = 0; i < nums.size(); i++){
            if(nums[i] != 0){
                nums[left++] = nums[i];
            }
            else
                count++;
        }
        for(int i = nums.size() - 1; i > nums.size() - 1 - count; i--){
            nums[i] = 0;
        }
    }
};