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
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> arr;
        dfs(root, "", arr);
        return arr;
    }
    
    void dfs(TreeNode* root, string str, vector<string>& arr){
        if(root == NULL) return;
        
        string currVal = to_string(root->val);
        if(root->left == NULL && root->right == NULL)
            arr.push_back(str + currVal);
        dfs(root->left, str + currVal + "->", arr);
        dfs(root->right, str + currVal + "->", arr);
    }
};