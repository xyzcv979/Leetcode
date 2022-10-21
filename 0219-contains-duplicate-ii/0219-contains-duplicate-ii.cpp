class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_map<int, vector<int>> dupMap;
        
        for(int i = 0; i < nums.size(); i++) {
            int num = nums[i];
            if(dupMap.find(num) != dupMap.end()) {
                for(auto& index : dupMap[num]) {
                    if(abs(index - i) <= k)
                        return true;
                }
            }
            dupMap[num].push_back(i);
        }
        return false;
    }
};