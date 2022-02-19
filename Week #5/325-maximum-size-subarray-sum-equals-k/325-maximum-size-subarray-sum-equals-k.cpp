class Solution {
public:
    int maxSubArrayLen(vector<int>& nums, int k) {
        int prefixSum = 0;
        int maxLen = 0;
        map<int,int> subArrays;
        for(int i = 0; i < nums.size(); i++){
            prefixSum += nums[i];
            if(prefixSum == k)
                maxLen = i + 1;
            if(subArrays.find(prefixSum - k) != subArrays.end()){
                maxLen = max(maxLen, i - subArrays[prefixSum - k]);
            }
            if(subArrays.find(prefixSum) == subArrays.end())
                subArrays[prefixSum] = i;
        }
        return maxLen;
    }
};