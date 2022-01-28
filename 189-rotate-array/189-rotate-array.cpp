class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> kNums(n);
        for(int i = 0; i < n; i++){
            kNums[i] = nums[i];
        }
        for(int i = 0; i < n; i++){
            nums[(i + k) % n] = kNums[i];
        }
    }
};