class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        vector<int> ret(nums.size());
        int left = 0, right = nums.size() -1;
        for(int i = nums.size() - 1; i >= 0; i--){
            int square;
            if(abs(nums[left]) > abs(nums[right])){
                square = nums[left];
                left++;
            }
            else{
                square = nums[right];
                right--;
            }
            ret[i] = square * square;
            
        }
        return ret;
    }
};