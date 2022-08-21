class Solution {
public:
    vector<int> movesToStamp(string stamp, string target) {
        vector<int> res;
        int totalStamp = 0, turnStamp = -1;
        
        while(turnStamp) {
            turnStamp = 0;
            for(int size = stamp.size(); size > 0; size--) {
                for(int i = 0; i <= stamp.size() - size; i++) {
                    
                    string newStamp = string(i, '*') + stamp.substr(i, size) + string(stamp.size() - size - i, '*');
                    int pos = target.find(newStamp);
                    while(pos != string::npos) {
                        res.push_back(pos);
                        turnStamp += size;
                        fill(begin(target) + pos, begin(target) + pos + stamp.size(), '*');
                        pos = target.find(newStamp);
                    }
                }
            }
            totalStamp += turnStamp;
        }
        reverse(begin(res), end(res));
        return totalStamp == target.size() ? res : vector<int>();
    }
};

/*
https://leetcode.com/problems/stamping-the-sequence/discuss/189576/C%2B%2B-simple-greedy

*/
