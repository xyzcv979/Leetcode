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
    TreeNode* addOneRow(TreeNode* root, int val, int depth) {
        if(depth == 1) {
            TreeNode* newRoot = new TreeNode(val);
            newRoot->left = root;
            return newRoot;
        }
        
        return dfs(root, val, depth, 1);
    }
    
    TreeNode* dfs(TreeNode* curr, int val, int depth, int currDepth) {
        if(!curr) return NULL;
        
        if(currDepth == depth - 1) {
            TreeNode* newLeft = new TreeNode(val, curr->left, nullptr);
            TreeNode* newRight = new TreeNode(val, nullptr, curr->right);
            
            curr->left = newLeft;
            curr->right = newRight;
            
            return curr;
        }
        
        curr->left = dfs(curr->left, val, depth, currDepth+1);
        curr->right = dfs(curr->right, val, depth, currDepth+1);
        
        return curr;
    }
};
/*
root depth = 1

bfs?
find all nodes on previous level


left side
newNode->left = left tree

right side 
newNode->right = right tree

*/