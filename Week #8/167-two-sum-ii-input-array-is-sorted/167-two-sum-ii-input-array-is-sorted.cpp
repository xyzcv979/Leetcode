class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        // nums is sorted
        // 2 pointer, start and end
        // if sum > target, decrem end. Else increm start
        
        vector<int> ret;
        int start = 0, end = numbers.size()-1;
        while(start < end){
            int currSum = numbers[start] + numbers[end];
            if(currSum == target){
                ret.push_back(start + 1);
                ret.push_back(end + 1);
                break;
            }
            else if(currSum > target)
                end--;
            else
                start++;
        }
        return ret;
    }
};