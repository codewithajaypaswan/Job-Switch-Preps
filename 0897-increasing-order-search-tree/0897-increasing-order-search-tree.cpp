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
    TreeNode* cur = NULL;
    void solve(TreeNode* root) {
        if(!root) return;
        solve(root->left);
        cur->right = new TreeNode(root->val);
        cur = cur->right;
        solve(root->right);
    }
    TreeNode* increasingBST(TreeNode* root) {
        TreeNode* dummy = new TreeNode(0);
        cur = dummy;
        solve(root);
        return dummy->right;
    }
};