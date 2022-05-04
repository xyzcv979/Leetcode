class Solution {
public:
    vector<int> findPermutation(string s) {
        vector<int> arr;
        int n = s.size();
        stack<int> stck;
        int count = 1;
        stck.push(count);
        for(char c : s){
            if(c == 'I'){
                
                while(!stck.empty()){
                    arr.push_back(stck.top());
                    stck.pop();
                }
                count++;
                stck.push(count);
            }
            else{
                count++;
                stck.push(count);
            }
        }
        while(!stck.empty()){
            arr.push_back(stck.top());
            stck.pop();
        }
        
        return arr;
    }
};