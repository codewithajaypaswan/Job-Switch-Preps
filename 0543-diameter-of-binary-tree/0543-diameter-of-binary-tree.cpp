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
    int height(TreeNode* root) {
        if(!root) return 0;
        return max(height(root->left), height(root->right)) + 1;
    }
    void solve1(TreeNode* root) {
        if(!root) return;
        int lh = height(root->left);
        int rh = height(root->right);
        ans = max(ans, lh + rh);
        solve1(root->left);
        solve1(root->right);
    }
    int diameterOfBinaryTree(TreeNode* root) {
        solve1(root);
        return ans;
    }
};