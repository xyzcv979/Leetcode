class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        // 3 diff nums s.t. sum closest to target
        int closestSum = INT_MAX;
        sort(nums.begin(), nums.end());
        for(int i = 0; i < nums.size(); i++){
            int start = i + 1, end = nums.size() - 1;
            while(start < end){
                int currSum = nums[i] + nums[start] + nums[end];
                if(abs(target - currSum) < abs(closestSum))
                    closestSum = target - currSum;

                if(currSum >= target)
                    end--;
                else if(currSum < target)
                    start++;
                
            }
        }
        return target - closestSum;
    }
};
