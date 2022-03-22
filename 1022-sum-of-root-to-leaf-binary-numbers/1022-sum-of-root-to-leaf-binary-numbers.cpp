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
    int ans = 0;
    int sumRootToLeaf(TreeNode* root) {
        int pathSum = 0;
        dfs(root, pathSum);
        return ans;
    }
    
    void dfs(TreeNode* root, int pathSum){
        if(root == NULL) return;
        
        pathSum <<= 1;
        pathSum += root->val;
        if(root->left == NULL && root->right == NULL)
            ans += pathSum;
        if(root->left != NULL)
            dfs(root->left, pathSum);
        if(root->right != NULL)
            dfs(root->right, pathSum);
    }

};