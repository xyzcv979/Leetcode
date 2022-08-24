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
    int longestConsecutive(TreeNode* root) {        
        int ans = 0;
        TreeNode* parent = NULL;
        helper(root, parent, ans);
        
        return ans;
    }
    
    pair<int,int> helper(TreeNode* root, TreeNode*& parent, int& ans){
        if (!root) return {0,0};
        
        pair<int,int> left = helper(root->left, root, ans);
        pair<int,int> right = helper(root->right, root, ans);
        
        ans = max(ans, left.first + right.second + 1);
        ans = max(ans, left.second + right.first + 1);
        
        int inc = 0, dec = 0;
        if (parent && root->val == parent->val + 1)
        {
            inc = max(left.first, right.first) + 1;
        }
        if (parent && root->val == parent->val -1)
        {
            dec = max(right.second, left.second) + 1;
        }
        
        return {inc, dec};
    }

};