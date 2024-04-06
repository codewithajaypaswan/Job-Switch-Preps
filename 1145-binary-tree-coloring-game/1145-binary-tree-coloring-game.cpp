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
    int lChildCount = 0, rChildCount = 0;
    bool btreeGameWinningMove(TreeNode* root, int n, int x) {
        n = dfs(root, x);
        int parentCount = n - lChildCount - rChildCount - 1;
        int mx = max({parentCount, lChildCount, rChildCount});
        return mx > n/2;
    }
    int dfs(TreeNode* root, int x) {
        if(!root) return 0;
        int left = dfs(root->left, x);
        int right = dfs(root->right, x);
        if(root->val == x) {
            lChildCount = left;
            rChildCount = right;
        }
        return left + right + 1;
    }
};