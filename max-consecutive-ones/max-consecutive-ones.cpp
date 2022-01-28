class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int maxOnes = 0;
        int localOnes = 0;
        for(int i = 0; i < nums.size(); i++){
            if(nums[i] == 1)
                localOnes++;
            else
                localOnes = 0;
            maxOnes = max(maxOnes, localOnes);
        }
        return maxOnes;
    }
};