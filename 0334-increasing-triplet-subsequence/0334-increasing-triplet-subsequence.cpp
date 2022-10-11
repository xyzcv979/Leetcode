class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        int n = nums.size();
        if(n < 3) return false;
        
        vector<int> minArray(n);
        int minNum = INT_MAX;
        for(int i = 0; i < n; i++) {
            minNum = min(minNum, nums[i]);
            minArray[i] = minNum;
        }
        
        vector<int> maxArray(n);
        int maxNum = INT_MIN;
        for(int i = n - 1; i >= 0; i--) {
            maxNum = max(nums[i], maxNum);
            maxArray[i] = maxNum;
        }
        
        for(int i = 1; i < n-1; i++) {
            if(minArray[i] != nums[i] && maxArray[i] != nums[i]) {
                return true;
            }
        }
        return false;
    }
};