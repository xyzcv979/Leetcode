class Solution {
public:
    int minSetSize(vector<int>& arr) {
        int n = arr.size();
        unordered_map<int, int> freq;
        
        for(int num : arr) {
            freq[num]++;
        }
        
        vector<pair<int,int>> freqPairs;
        for(auto it : freq) {
            freqPairs.push_back({it.second, it.first});
        }
        
        sort(freqPairs.rbegin(), freqPairs.rend());
        
        int setSize = 0;
        int arrSize = n;
        int idx = 0;
        while(arrSize > (n/2)) {
            arrSize -= freqPairs[idx].first;
            setSize++;
            idx++;
        }
        
        return setSize;
    }
};
/*
7777
set = 7

12345

set = 123 or 345 or 125 or ...

freq map, sort by counts, 
*/