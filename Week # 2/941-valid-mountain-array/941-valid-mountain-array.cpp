// Reference: https://leetcode.com/problems/valid-mountain-array/discuss/451553/C%2B%2B-Simple-Solution-with-Explanations-for-newbies-less3

class Solution {
public:
    bool validMountainArray(vector<int>& arr) {
        if(arr.size() < 3)
            return false;
        
        int ptr = 1;
        while(ptr < arr.size()){
            if(arr[ptr] <= arr[ptr - 1])
                break;
            ptr++;
        }
        if(ptr == arr.size() || ptr == 1)
            return false;
        while(ptr < arr.size()){
            if(arr[ptr] >= arr[ptr - 1])
                break;
            ptr++;
        }
        
        return ptr == arr.size();
       
    }
};