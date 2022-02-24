class Solution {
public:
    int maxProduct(vector<int>& nums) {
        // Consider 0 and negative values
        // when neg val * neg value = pos
        int maxProduct = nums[0], minProduct = nums[0];
        int ans = maxProduct;
        for(int i = 1; i < nums.size(); i++){
            int currVal = nums[i];
            if(currVal < 0)
                swap(maxProduct, minProduct);
            maxProduct = max(currVal, maxProduct * currVal);
            minProduct = min(currVal, minProduct * currVal);
            ans = max(ans, maxProduct);
        }
        
        return ans;
    }
};