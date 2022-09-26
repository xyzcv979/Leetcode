class Solution {
public:
    vector<int> parent;
    
    int find(int x) {
        if(parent[x] == x) return x;
        return parent[x] = find(parent[x]);
    }
    
    bool equationsPossible(vector<string>& equations) {
        int n = equations.size();
        parent = vector<int>(26);
            
        for(int i = 0; i < 26; i++)
            parent[i] = i;
        
        // Handle == case like a==b
        for(string expr : equations) {
            if(expr[1] == '=') {
                // combining groups
                // set parent of a = parent of b
                parent[find(expr[0] - 'a')] = find(expr[3]-'a');
            }
        }
        
        // handle != case
        for(string expr : equations) {
            // != case and both parents are same. This is contradiction
            if(expr[1] == '!' && find(expr[0]-'a') == find(expr[3]-'a'))
                return false;
        }
        
        return true;
    }
};

/*
2 graphs: connected components
== graph

!= graph

any contradiction = false


2 approaches: 
dfs w/ coloring visited nodes
union find
*/
