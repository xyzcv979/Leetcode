class Solution {
public:
    typedef pair<int, int> pi;
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        sort(arr.begin(), arr.end(), [x](int &a, int &b) {
            if(abs(a-x) < abs(b-x)) {
                return true;
            } else if(abs(a-x) == abs(b-x)) {
                return a<b;
            }
            return false;
        });
        
        vector<int> ans;
        for(int i = 0; i < k; i++) {
            ans.push_back(arr[i]);
        }
        sort(ans.begin(), ans.end());
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