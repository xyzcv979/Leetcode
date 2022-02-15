class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        map<int, int> pairs;
        vector<int> ret;
        int remaind = 0;
        for(int i = 0; i < nums.size(); i++){
            remaind = target - nums[i];
            if(pairs.find(remaind) != pairs.end()){
                ret.push_back(pairs[remaind]);
                ret.push_back(i);
                break;
            }
            pairs[nums[i]] = i;
        }
        return ret;
            
    }
};