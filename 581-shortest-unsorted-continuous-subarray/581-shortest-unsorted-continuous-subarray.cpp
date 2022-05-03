class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        vector<int> sortedNums(nums);
        sort(sortedNums.begin(), sortedNums.end());
        int len = sortedNums.size();
        int left = 0, right = len - 1;
        while(left < len && nums[left] == sortedNums[left]){
            left++;
        }
        
        while(right > left && nums[right] == sortedNums[right]){
            right--;
        }
        
        return right - left + 1;
    }
};


/*
2 6 4 8 10 9 15

when curr < prev, swap?
stack?
*/