class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> arr;
        sort(nums.begin(), nums.end());
        for(int i = 0; i < nums.size() && nums[i] <= 0; i++){
            if(i == 0 || nums[i - 1] != nums[i])
                twoSumII(nums, i, arr);
        }
        return arr;
    }
    
    void twoSumII(vector<int>& nums, int i, vector<vector<int>>& arr){
        int low = i + 1, high = nums.size() - 1;
        int sum = 0;
        while(low < high){
            sum = nums[i] + nums[low] + nums[high];
            if(sum == 0){
                arr.push_back(vector<int>{nums[i], nums[low], nums[high]});
                low++;
                high--;
                while(low < high && nums[low] == nums[low - 1])
                    low++;
            }
            else if(sum < 0)
                low++;
            else
                high--;
            
            
        }
    }
};