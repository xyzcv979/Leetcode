class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> freq;
        int n = nums.size();
        
        for(int num : nums) {
            freq[num]++;
        }
        
        vector<vector<int>> buckets(n + 1);
        for(auto it : freq) {
            buckets[it.second].push_back(it.first);
        }
        
        vector<int> ans;
        for (int i = n; i >= 0; i--) {
            if (ans.size() >= k) {
                break;
            }
            if (!buckets[i].empty()) {
                ans.insert(ans.end(), buckets[i].begin(), buckets[i].end());
            }
        }
        
        return ans;
    }
};

/*
to get o(n) time and space

bucket sort

hashmap to find counts
have array of counts mapped to the values with those counts
loop from reverse to get top k counts
*/