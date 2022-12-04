class Solution {
public:
    int minimumAverageDifference(vector<int>& nums) {
        int n = nums.size();
        vector<long long> prefix(n,0), suffix(n,0);
        int minDiff = INT_MAX;
        int minDiffIdx = 0;
        
        prefix[0] = nums[0];
        for(int i = 1; i < n; i++) {
            prefix[i] = prefix[i-1] + nums[i]; 
        }
        
        suffix[n-1] = nums[n-1];
        for(int i = n-2; i >= 0; i--) {
            suffix[i] = suffix[i+1] + nums[i];
        }
        
        for(int i = 0; i < n; i++) {
            int firstHalfCount = i + 1;
            int secHalfCount = n - i - 1;
            long long firstHalfSum = prefix[i];
            long long secHalfSum;
            
            // Last element
            if(i == n -1) {
                secHalfSum = 0;
                secHalfCount = 1;
            } else {
                secHalfSum = suffix[i+1];
            }
            
            int diff = abs((firstHalfSum/firstHalfCount) - (secHalfSum/secHalfCount));
            if(diff < minDiff) {
                minDiff = diff;
                minDiffIdx = i;
            }
        }
        
        return minDiffIdx;
    }
};

/*
at index i, add up all prefixes and divde by that count of nums
subtract that with all suffixes, divided by the count

|first i - last i|
first i = sum of prefixes / count of nums

prefix/suffix array
*/