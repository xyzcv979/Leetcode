class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adjList(numCourses, vector<int>());
        vector<int> indegrees(numCourses,0);
        
        for(auto& p : prerequisites) {
            adjList[p[1]].push_back(p[0]);
            indegrees[p[0]]++;
        }
        
        queue<int> que;
        for(int i = 0; i < numCourses; i++) {
            if(indegrees[i] == 0) {
                que.push(i);
            }
        }
        while(!que.empty()) {
            int curr = que.front();
            que.pop();
            numCourses--; // check for cycles?
            
            // loop neighbors to remove indegrees
            for(int neigh : adjList[curr])
                if(--indegrees[neigh] == 0) que.push(neigh);
        }
        
        return numCourses == 0;
    }
};

/*
topological sorting
put nodes into queue that have 0 indegrees
*/