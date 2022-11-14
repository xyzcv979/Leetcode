class Solution {
public:
    vector<bool> visited;
    int removeStones(vector<vector<int>>& stones) {
        visited = vector<bool>(stones.size());
        int connectedComponents = 0;
        for(int i = 0; i < stones.size(); i++) {
            if(!visited[i]) {
                dfs(stones, visited, i);
                connectedComponents++;
            }
        }
        return stones.size() - connectedComponents;
    }
    
    void dfs(vector<vector<int>>& stones, vector<bool> &visited, int i) {
        visited[i] = true;
        
        for(int j = 0; j < stones.size(); j++) {
            // visited contains this curr pair
            if(visited[j]) continue;
            if(stones[i][0] == stones[j][0] || stones[i][1] == stones[j][1]) {
                dfs(stones, visited, j);
            }
        }
    }
};


/*
0 0 0 0
0 
0
0

x  x  
 x
x  x

for every column/row w/ a stone
no matter odd/even # of stones
there will be 1 left

so find unique num of stones on col/row

same col / same row
can do disjoint set, group them


*/