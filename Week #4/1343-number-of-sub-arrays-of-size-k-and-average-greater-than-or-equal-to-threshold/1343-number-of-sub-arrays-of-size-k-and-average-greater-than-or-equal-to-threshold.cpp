class Solution {
public:
    int numOfSubarrays(vector<int>& arr, int k, int threshold) {
        // sliding window
        
        int count = 0;
        int window_sum = 0;
        // find sum of first k elements
        for(int i = 0; i < k; i++){
            window_sum += arr[i];
        }
        if(window_sum / k >= threshold)
            count++;
        
        // find window averages
        for(int i = k; i < arr.size(); i++){
            // slide window by 1 ele
            // take out 1st ele, add last ele
            window_sum -= arr[i-k];
            window_sum += arr[i];
            if(window_sum / k >= threshold)
                count++;
        }
        return count;
    }
};