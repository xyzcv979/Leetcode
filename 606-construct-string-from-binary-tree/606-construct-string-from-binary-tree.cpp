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
        
        string sVal = to_string(root->val);
        string left = dfs(root->left);
        string right = dfs(root->right);
        
        if(!root->left && !root->right) {
            return sVal;
        }
        if(!root->right) {
            return sVal + "(" + left + ")";
        }
        
        return sVal + "(" + left + ")" + "(" + right + ")"; 
    }

};


