class Solution {
private:
    int MOD = 1e9+7;
public:
    
    int sumSubarrayMins(vector<int>& arr) {
        long long sum = 0;
        int n = arr.size();
        stack<int> incStckPrev, incStckNext;
        vector<int> prevLessEle(n), nextLessEle(n);
        
        for(int i = 0; i < n; i++) {
            prevLessEle[i] = i + 1;
            nextLessEle[i] = n - i;
        }
        
        for(int i = 0; i < n; i++) {
            //fill prev less stack
            while(!incStckPrev.empty() && arr[incStckPrev.top()] > arr[i])
                incStckPrev.pop();
            prevLessEle[i] = incStckPrev.empty() ? i + 1 : i - incStckPrev.top();
            incStckPrev.push(i);
            
            //fill next less stack
            while(!incStckNext.empty() && arr[incStckNext.top()] > arr[i]) {
                nextLessEle[incStckNext.top()] = i - incStckNext.top();
                incStckNext.pop();
            }
            incStckNext.push(i);
        }
        
        for(int i = 0; i < n; i++) {
            sum = (sum + 1LL * arr[i]*prevLessEle[i]*nextLessEle[i])%MOD;
        }
        
        return (int)sum;
    }
};