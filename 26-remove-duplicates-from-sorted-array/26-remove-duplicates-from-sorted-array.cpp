class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        // 2 pointer
        int k = 1;
        int left = 0;
        for(int i = 1; i < nums.size(); i++){
            if(nums[i] != nums[left]){
                left++;
                nums[left] = nums[i];
                k++;
            }
        }
        return k;
    }
};