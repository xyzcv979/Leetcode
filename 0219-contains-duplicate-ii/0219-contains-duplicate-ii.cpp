class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_map<int,int> mp;
        
        for(int i = 0; i < nums.size(); i++) {
            int num = nums[i];
            if(mp.count(num) && i - mp[num] <= k)
                return true;
            mp[num] = i;
        }
        return false;
    }
};