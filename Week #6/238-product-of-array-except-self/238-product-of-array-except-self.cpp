class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        // answer[i] = product of all nums except nums[i]
        // Idea: prefix[i] * suffix[i] = answer[i]
        
        int n = nums.size();
        
        vector<int> answer(n,1);
        for(int i = 1; i < n; i++){
            answer[i] = answer[i - 1] * nums[i-1];
        }
        
        int suffixProduct = 1;
        for(int i = n - 1; i >= 0; i--){
            answer[i] = answer[i] * suffixProduct;
            suffixProduct *= nums[i];
        }
        return answer;
    }
};