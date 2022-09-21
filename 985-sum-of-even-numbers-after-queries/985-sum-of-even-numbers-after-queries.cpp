class Solution {
public:
    vector<int> sumEvenAfterQueries(vector<int>& nums, vector<vector<int>>& queries) {
        vector<int> evenSums;
        int rollingSum = 0;
        
        for(int num : nums) {
            if(num % 2 == 0)
                rollingSum += num;
        }

        for(auto query : queries) {
            int i = query[1];
            int val = query[0];
            
            if(nums[i] % 2 == 0) {
                rollingSum -= nums[i];    
            }
            
            nums[i] += val;
            
            if(nums[i] % 2 == 0) {
                rollingSum += nums[i];    
            }
            
            evenSums.push_back(rollingSum);
        }
        
        return evenSums;
    }
};

/*
rollingSum, add all evens to it

everytime you update,
old val + new val, if updated val is even, add value
else do nothin

oldVal is odd
updatedVal is even
add updatedVal

oldVal is even
updatedVal is even
add

oldVal is odd
updatedVal is odd

oldVal is even
updatedVal is odd


*/