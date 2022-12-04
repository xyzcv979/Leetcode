class Solution {
public:
    int minimumAverageDifference(vector<int>& nums) {
        int n = nums.size();
        int minDiff = INT_MAX;
        int minDiffIdx = 0;
        long long totalSum = 0;
        long long prefixSum = 0;
        
        for(int i : nums) {
            totalSum += i;
        }
        
        for(int i = 0; i < n; i++) {
            int firstHalfCount = i + 1;
            int secHalfCount = n - i - 1;
            long long secHalfSum;
            
            prefixSum += nums[i];
            
            // Last element
            if(i == n -1) {
                secHalfSum = 0;
                secHalfCount = 1;
            } else {
                secHalfSum = totalSum - prefixSum;
            }
            
            int diff = abs((prefixSum/firstHalfCount) - (secHalfSum/secHalfCount));
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