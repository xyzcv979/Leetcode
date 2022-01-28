class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int start = 0;
        int end = numbers.size() - 1;
        vector<int> ret;
        while(start != end){
            if(numbers[start] + numbers[end] == target){
                ret.push_back(start + 1);
                ret.push_back(end + 1);
                break;
            }
            if(numbers[start] + numbers[end] < target)
                start++;
            else{
                end--;
            }
        }
        return ret;
    }
};