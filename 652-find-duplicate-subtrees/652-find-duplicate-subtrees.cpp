/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<TreeNode*> ans;
    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
        unordered_map<string, vector<TreeNode*>> map;
        dfs(root, map);
        
        for(auto it : map) {
            if(it.second.size() > 1)
                ans.push_back(it.second[0]);
        }
        return ans;
    }
    
    string dfs(TreeNode* root, unordered_map<string, vector<TreeNode*>>& map) {
        if(!root) return "";
        
        string s = to_string(root->val);
        string left = dfs(root->left, map);
        string right = dfs(root->right, map);
        
        s = s + "(" + left + ")(" + right + ")";
        
        map[s].push_back(root);
        
        return s;
        
    }
};