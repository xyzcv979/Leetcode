class Solution {
public:
    bool isPossible(vector<int>& nums) {
        unordered_map<int,int> freq, end;
        
        for(int num : nums) 
            freq[num]++;
        
        for(int num : nums) {
            if(!freq[num]) continue;
            freq[num]--;
            
            if(end[num-1] > 0) {
                end[num-1]--;
                end[num]++;
            } else if(freq[num + 1] && freq[num + 2]) {
                freq[num+1]--;
                freq[num+2]--;
                end[num+2]++;
            } else {
                return false;
            }
        }
        
        return true;
    }
};

/*


*/

