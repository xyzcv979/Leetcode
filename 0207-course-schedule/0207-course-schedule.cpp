class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        int n = prerequisites.size();
        map<int, vector<int>> adjMap;
        unordered_set<int> visited;
        
        // build adj list
        for(int i = 0; i < n; i++) {
            adjMap[prerequisites[i][0]].push_back(prerequisites[i][1]);
        } 
        
        for(int i = 0; i < numCourses; i++) {
            if(!dfs(adjMap, visited, i)) {
                return false;
            }
        }
        return true;
    }
    
    bool dfs(map<int, vector<int>>& adjMap, unordered_set<int>& visited, int courseNum) {
        if(visited.find(courseNum) != visited.end()) // Cycle detected
            return false;
        
        vector<int> neighbors = adjMap[courseNum];
        if(neighbors.empty())
            return true;
        
        visited.insert(courseNum);
        
        for(int i = 0; i < neighbors.size(); i++) {
            if(!dfs(adjMap, visited, neighbors[i]))
                return false;
            
        }
        adjMap[courseNum].clear(); // As long as you're getting true from this path, delete its adjacent nodes
        visited.erase(courseNum);
        return true;
    }
};

/*
topological sorting

0 -> 2 -> 3 -> 4
|
v
1

dfs till end, mark end points as done

cycle = not possible
*/