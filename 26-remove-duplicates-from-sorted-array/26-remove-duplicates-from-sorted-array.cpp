class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int k = 1;
        int left = 0;
        int right = nums.size() - 1;
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