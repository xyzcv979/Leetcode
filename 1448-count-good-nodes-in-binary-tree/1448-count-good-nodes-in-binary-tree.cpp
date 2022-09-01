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
    int goodNodesCount;
    int goodNodes(TreeNode* root) {
        goodNodesCount = 0;
        dfs(root, root->val);
        return goodNodesCount;
    }
    
    void dfs(TreeNode* root, int highest) {
        if(!root) return;
        
        if(root->val >= highest) {
            highest = root->val;
            goodNodesCount++;
        }
        
        dfs(root->left, highest);
        dfs(root->right, highest);
    }
};