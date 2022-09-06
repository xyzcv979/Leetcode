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
    TreeNode* pruneTree(TreeNode* root) {
        prune(root);
        
        if(root->val == 0 && !root->left && !root->right)
            return NULL;
        return root;
    }
    
    TreeNode* prune(TreeNode* root) {
        if(!root) return NULL;
        
        root->left = prune(root->left);
        root->right = prune(root->right);
        
        if(!root->left && !root->right && root->val == 0)
            return NULL;
        
        return root;
    }
};