class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        // answer[i] = product of all nums except nums[i]
        // Idea: prefix[i] * suffix[i] = answer[i]
        
        int n = nums.size();
        
        vector<int> answer(n);
        vector<int> prefix(n);
        vector<int> suffix(n);
        
        prefix[0] = 1;
        for(int i = 1; i < n; i++){
            prefix[i] = prefix[i-1] * nums[i-1];
        }
        
        suffix[n-1] = 1;
        for(int i = n - 2; i >= 0; i--){
            suffix[i] = nums[i+1] * suffix[i+1];
        }
        
        for(int i = 0; i < n; i++){
            answer[i] = prefix[i] * suffix[i];
        }
        return answer;
    }
};