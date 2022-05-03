class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        int n = nums.size();
        
        int left = 0, right = 0;
        int prev = nums[0];
        for(int i = 0; i < n; i++){ // finding end most index out of place
            if(nums[i] < prev){
              right = i;
            } 
            else prev = nums[i];
        }
        prev = nums[n-1];
        for(int i = n-1; i >= 0; i--){ // finding start most index out of place
            if(nums[i] > prev) left = i;
            else prev = nums[i];
        }
        return right != 0 ? right - left + 1 : 0;
        
    }
};


/*

*/