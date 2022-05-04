class Solution {
public:
    int maxOperations(vector<int>& nums, int k) {
        int count = 0;
        int n = nums.size();
        
       sort(nums.begin(), nums.end());
        int left = 0, right = n-1;
        while(left < right){
            int curr = nums[left] + nums[right];
            if(curr == k){
                count++;
                left++;
                right--;
            }
            else if(curr > k) right--;
            else left++;
            
        }
        return count;
    }
};