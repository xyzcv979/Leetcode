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
    string tree2str(TreeNode* root) {
        return dfs(root);
    }
    
    
    string dfs(TreeNode* root) {
        if(!root)
            return "";
        
        string val = to_string(root->val);
        string s;

        string left = dfs(root->left);
        string right = dfs(root->right);
        
        if(root->left && root->right) {
            s = val + "(" + left + ")(" + right + ")";
        }
        else if(!root->left && root->right) {
            s = val + "()(" + right + ")";
        } else if(root->left && !root->right) {
            s = val + "(" + left + ")";
        } else 
            s = val + left + right;
        
        return s; 
    
    }
};


