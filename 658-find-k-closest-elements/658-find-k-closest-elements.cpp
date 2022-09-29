class Solution {
public:
    typedef pair<int, int> pi;
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        priority_queue<pi, vector<pi>, greater<pi>> minHeap;
        
        for(int num : arr) {
            int diff = abs(num - x);
            minHeap.push({diff, num});
        }
        
        vector<int> ans;
        while(k) {
            ans.push_back(minHeap.top().second);
            minHeap.pop();
            k--;
        }
        sort(ans.begin(),ans.end());
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