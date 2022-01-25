class Solution {
public:
    bool validMountainArray(vector<int>& arr) {
        if(arr.size() < 3)
            return false;
        
        int ptr = 1;
        while(ptr < arr.size()){
            if(arr[ptr] <= arr[ptr - 1]){
                break;
            }
            ptr++;
        }
        if(ptr == arr.size() || ptr == 1){
            return false;
        }
        while(ptr < arr.size()){
            if(arr[ptr] >= arr[ptr - 1]){
                break;
            }
            ptr++;
        }
        
        return ptr == arr.size();
       
    }
};