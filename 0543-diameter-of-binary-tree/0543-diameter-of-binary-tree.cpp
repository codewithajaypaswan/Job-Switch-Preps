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
        // solve1(root);
        solve2(root);
        return ans;
    }
    int solve2(TreeNode* root) {
        if(!root) return 0;
        int lh = solve2(root->left);
        int rh = solve2(root->right);
        ans = max(ans,lh + rh);
        return 1 + max(lh, rh);
    }
};