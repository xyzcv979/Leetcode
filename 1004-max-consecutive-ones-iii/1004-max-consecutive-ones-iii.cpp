class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int maxOnes = 0;
        int left = 0, right = 0;
        int numZeroes = 0;
        while(right < nums.size()){
            if(nums[right] == 0)
                numZeroes++;
            while(numZeroes > k){
                if(nums[left] == 0)
                    numZeroes--;
                left++;
            }
            
            maxOnes = max(maxOnes, right - left + 1);
            right++;
        }
        return maxOnes;
    }
};