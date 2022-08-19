class Solution {
public:
    bool isPossible(vector<int>& nums) {
        unordered_map<int,int> freq, end;
        
        for(int num : nums) 
            freq[num]++;
        
        for(int num : nums) {
            if(!freq[num]) continue;
            freq[num]--;
            
            // checking valid subsequence
            if(end[num-1] > 0) {
                end[num-1]--;
                end[num]++;
            } 
            // starting a new subsequence = need num+1 and num+2 to exist
            else if(freq[num + 1] && freq[num + 2]) {
                freq[num+1]--;
                freq[num+2]--;
                end[num+2]++;
            } else { // no valid subsequence is possible
                return false;
            }
        }
        
        return true;
    }
};

/*


*/

