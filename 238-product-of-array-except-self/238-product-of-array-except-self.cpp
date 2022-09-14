class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> prefix(n), suffix(n);
        
        vector<int> ans(n);
        
        int currProduct = 1;
        for(int i = 0; i < n; i++) {
            prefix[i] = currProduct;
            currProduct *= nums[i];
        }
        
        currProduct = 1;
        for(int i = n-1; i >= 0; i--) {
            suffix[i] = currProduct;
            currProduct *= nums[i];
        }
        
        for(int i = 0; i < n; i++) {
            ans[i] = suffix[i] * prefix[i];
        }
        
        return ans;
    }
};

/*
1 2 3

*/