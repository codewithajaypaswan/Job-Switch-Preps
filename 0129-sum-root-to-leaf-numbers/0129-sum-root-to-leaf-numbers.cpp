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
    int ans = 0;
    void solve(TreeNode* root, int val) {
        if(!root) return;
        val = val * 10 + root->val;
        if(!root->left && !root->right) {
            ans += val;
        }
        solve(root->left, val);
        solve(root->right, val);
    }
    int sumNumbers(TreeNode* root) {
        solve(root, 0);
        return ans;
    }
};