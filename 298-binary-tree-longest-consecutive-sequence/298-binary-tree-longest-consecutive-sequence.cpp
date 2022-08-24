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
        dfs(root, INT_MIN, 1);
        return maxCount;
    }
    
    void dfs(TreeNode* root, int prevVal, int count) {
        if(!root) return;
        
        int newCount = count;
        if(root->val == prevVal + 1) {
            newCount++;
        } else {
            newCount = 1;
        }
        
        maxCount = max(newCount, maxCount);
        
        dfs(root->left, root->val, newCount);
        dfs(root->right, root->val, newCount);
    }
};