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
        if(depth - 1 == 0) {
            TreeNode* newNode = new TreeNode(val);
            newNode->left = root;
            return newNode;
        }
        queue<TreeNode*> que;
        vector<vector<TreeNode*>> levels;
        
        que.push(root);
        while(!que.empty()) {
            int size = que.size();
            vector<TreeNode*> level;
            for(int i = 0; i < size; i++) {
                TreeNode* curr = que.front();
                que.pop();
                
                if(curr->left) que.push(curr->left);
                if(curr->right) que.push(curr->right);
                level.push_back(curr);
            }
            
            levels.push_back(level);
        }
        
        
        for(auto currNode : levels[depth-2]) {
            TreeNode* newLeft = new TreeNode(val, currNode->left, nullptr);
            TreeNode* newRight = new TreeNode(val, nullptr, currNode->right);
            
            currNode->left = newLeft;
            currNode->right = newRight;
        }
        
        return root;
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