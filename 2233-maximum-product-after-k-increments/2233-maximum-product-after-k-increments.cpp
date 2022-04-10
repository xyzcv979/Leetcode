class Solution {
public:
    int maximumProduct(vector<int>& nums, int k) {
        priority_queue<int, vector<int>, greater<int>> pq;
        int modNum = pow(10, 9) + 7;
        
        for(int i : nums)
            pq.push(i);
        
        while(k--){
            int top = pq.top();
            pq.pop();
            top++;
            pq.push(top);
        }
        
        long long res = 1;
        while(!pq.empty()){
            res = (res * pq.top()) % modNum;
            pq.pop();
        }
        return res;
    }
};