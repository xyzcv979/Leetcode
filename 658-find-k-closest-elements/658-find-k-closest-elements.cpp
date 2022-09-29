class Solution {
public:
    typedef pair<int, int> pi;
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        int left = 0, right = arr.size() - k;
        
        while(left < right) {
            int mid = left + (right - left) / 2;
            
            if(x - arr[mid] > arr[mid + k] - x) {
                left = mid + 1;
            } else {
                right = mid;
            }
        }
        
        vector<int> ans;
        for(int i = left; i < left + k; i++) {
            ans.push_back(arr[i]);
        }
        
        return ans;
    }
};
/*
binary search to find element or closest element if not there

if x is left of arr, return first k ele
if x is right of arr, return last k ele

or just use formual a - x for all ele in arr
store in map?
sort by the diff, return k values w/ smallest diff
*/