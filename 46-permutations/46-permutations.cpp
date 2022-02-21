class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> permutations;
        backtrack(nums, 0, permutations);
        return permutations;
    }
    
    void backtrack(vector<int> &nums, int i, vector<vector<int>> &perms){
        if(i == nums.size())
            perms.push_back(nums);
        else{
            for(int j = i; j < nums.size(); j++){
                swap(nums[i], nums[j]);
                backtrack(nums, i + 1, perms);
                swap(nums[i], nums[j]);
            }
        }
    }
};