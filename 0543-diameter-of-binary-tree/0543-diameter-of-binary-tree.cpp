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
    int ans = INT_MIN;
    int height(TreeNode* root) {
        if(!root) return 0;
        return max(height(root->left), height(root->right)) + 1;
    }
    void dfs(TreeNode* root) {
        if(!root) return;
        int ld = height(root->left);
        int rd = height(root->right);
        ans = max(ans, ld + rd);
        dfs(root->left);
        dfs(root->right);
    }
    int diameterOfBinaryTree(TreeNode* root) {
        dfs(root);
        return ans;
    }
};