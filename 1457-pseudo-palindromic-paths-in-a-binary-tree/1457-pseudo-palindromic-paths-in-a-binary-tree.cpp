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
    int palinPaths;
    int pseudoPalindromicPaths (TreeNode* root) {
        palinPaths = 0;
        vector<int> counts(10);
        dfs(root, counts);
        return palinPaths;
    }
    
    void dfs(TreeNode* root, vector<int> counts) {
        if(!root)
            return;

        counts[root->val]++;
        
        if(!root->left && !root->right) { // leaf node
            bool oneOdd = false;
            for(int i : counts) {
                if(i % 2 != 0) {
                    if(oneOdd) // 2 odd counts, not a palindrome
                        return;
                    oneOdd = true;
                }
            }
            palinPaths++;
        }
        
        dfs(root->left, counts);
        dfs(root->right, counts);
    }
    
};
