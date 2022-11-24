class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> order;
        vector<int> indegrees(numCourses,0);
        vector<vector<int>> adjList(numCourses,vector<int>());
        
        // Create adjList and incr indegrees
        for(auto& pre : prerequisites) {
            adjList[pre[1]].push_back(pre[0]);
            indegrees[pre[0]]++;
        }
        
        queue<int> zeroNodes;
        for(int i = 0; i < numCourses; i++) {
            if(indegrees[i] == 0) 
                zeroNodes.push(i);
        }

        int coursesPopped = 0;
        while(!zeroNodes.empty()) {
            int curr = zeroNodes.front();
            zeroNodes.pop();
            coursesPopped++;
            order.push_back(curr);
            for(auto& neigh : adjList[curr]) {
                if(--indegrees[neigh] == 0)
                    zeroNodes.push(neigh);
            }
        }
        
        if(coursesPopped == numCourses)
            return order;
        
        return vector<int>();
    }
};

/*
topological sorting: kahns algorithm

build adjList
build indegree array
loop queue, pop out nodes, decrement its neighbors indegrees
push to queue nodes with 0 indegrees

*/