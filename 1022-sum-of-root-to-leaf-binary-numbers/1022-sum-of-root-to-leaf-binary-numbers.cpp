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
    int ans = 0;
public:
    int sumRootToLeaf(TreeNode* root) {
        int pathNum = 0;
        dfs(root, pathNum);
        return ans;
    }
    
    void dfs(TreeNode* root, int pathNum){
        if(root == NULL) return;
        
        pathNum <<= 1; // Shift by 1
        pathNum += root->val; // Either 1 or 0
        if(root->left == NULL && root->right == NULL)
            ans += pathNum;
        
        if(root->left != NULL) dfs(root->left, pathNum);
        if(root->right != NULL) dfs(root->right, pathNum);
        
    }
};