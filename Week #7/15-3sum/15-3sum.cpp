class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> ret;
        for(int i = 0; i < nums.size(); i++){
            if(nums[i] > 0) // Nothing else adds up to 0
                break;
           if(i == 0 || nums[i] != nums[i-1])
                twoSum(nums, i, ret);
        }
        return ret;
    }
    
    void twoSum(vector<int>& nums, int i, vector<vector<int>>& ret){
        unordered_set<int> set;
        for(int j = i + 1; j < nums.size(); j++){
            int curr = -nums[j] - nums[i];
            if(set.count(curr)){
                ret.push_back({nums[i], curr, nums[j]});
                while(j+1 < nums.size() && nums[j] == nums[j+1]) // skip duplicates
                    j++;
            }
            set.insert(nums[j]);
        }
    }
    
};