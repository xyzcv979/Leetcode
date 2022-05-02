class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& nums) {
        vector<int> arr;
        for(int i : nums){
            if(i % 2 == 0) arr.push_back(i);
        }
        for(int i : nums){
            if(i % 2 != 0) arr.push_back(i);
        }
        
        return arr;
    }
};