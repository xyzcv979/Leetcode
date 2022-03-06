class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> ret;
        for(int i = 0; i < nums.size(); i++){
            if(i != 0 && nums[i] == nums[i-1])
                continue;
            
            int start = i + 1, end = nums.size() - 1;
            while(start < end){
                int currSum = nums[i] + nums[start] + nums[end];
                if(currSum == 0){
                    ret.push_back({nums[i], nums[start], nums[end]});
                    start++;
                    while(nums[start] == nums[start - 1] && start < end)
                        start++;
                }
                else if(currSum > 0)
                    end--;
                else // if currsum < 0
                    start++;
            }
        }
        return ret;
    }
    
    
};