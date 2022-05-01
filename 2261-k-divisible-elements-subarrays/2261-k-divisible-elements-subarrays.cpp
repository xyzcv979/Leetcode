class Solution {
public:
    int countDistinct(vector<int>& nums, int k, int p) {
        int n = nums.size();
        unordered_set<string> st;
        
        for(int i = 0; i < n; i++){
            string curr = "";
            int kCount = 0;
            for(int j = i; j < n; j++){
                curr += nums[j] + '0';
                if(nums[j] % p == 0) kCount++;
                if(kCount <= k) st.insert(curr);
                else break;
            }
        }
        
        return st.size();
    }
};