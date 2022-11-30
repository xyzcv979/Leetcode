class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        unordered_map<int,int> freq;
        for(int i : arr) {
            freq[i]++;
        }
        
        unordered_set<int> st;
        for(auto it : freq) {
            if(st.find(it.second) != st.end())
                return false;
            st.insert(it.second);
        }
        return true;
    }
};