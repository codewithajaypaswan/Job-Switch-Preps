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
    int maxDepth = 0;
    int findDepth(TreeNode* root) {
        if(!root) return 0;
        return 1 + max(findDepth(root->left), findDepth(root->right));
    }
    int solve(TreeNode* root, int depth) {
        if(!root) return 0;
        if(depth == maxDepth) return root->val;
        return solve(root->left, depth+1) + solve(root->right, depth + 1);
    }
    int deepestLeavesSum(TreeNode* root) {
        maxDepth = findDepth(root);
        return solve(root, 1);
    }
};