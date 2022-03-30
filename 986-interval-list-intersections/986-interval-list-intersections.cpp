class Solution {
public:
    vector<vector<int>> intervalIntersection(vector<vector<int>>& firstList, vector<vector<int>>& secondList) {
        vector<vector<int>> ret;
        int firstPtr = 0;
        int secPtr = 0;
        while(firstPtr < firstList.size() && secPtr < secondList.size()){
            int first = max(firstList[firstPtr][0], secondList[secPtr][0]);
            int sec = min(firstList[firstPtr][1], secondList[secPtr][1]);
            
            
            if(first <= sec)
                ret.push_back({first, sec});
            
            if(firstList[firstPtr][1] < secondList[secPtr][1])
                firstPtr++;
            else
                secPtr++;
        }
        return ret;
    }
};