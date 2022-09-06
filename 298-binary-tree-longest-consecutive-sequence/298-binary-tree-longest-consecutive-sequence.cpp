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
    int maxCount;
    int longestConsecutive(TreeNode* root) {
        maxCount = 0;
        dfs(root, root->val, 1);
        return maxCount;
    }
    
    void dfs(TreeNode* root, int prevVal, int count) {
        if(!root) return;
        
        if(root->val == prevVal + 1) {
            count++;
        } else {
            count = 1;
        }
        
        maxCount = max(maxCount, count);
        
        dfs(root->left, root->val, count);
        dfs(root->right, root->val, count);
    }
};