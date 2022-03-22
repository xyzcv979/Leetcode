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
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> arr;
        if(root == NULL)
            return arr;
        stack<TreeNode*> stck;
        TreeNode* curr = root;
        while(curr != NULL || !stck.empty()){
            while(curr != NULL){
                stck.push(curr);
                curr = curr->left;
            }
            curr = stck.top();
            stck.pop();
            arr.push_back(curr->val);
            curr = curr->right;
            
        }
        return arr;
    }
    

};