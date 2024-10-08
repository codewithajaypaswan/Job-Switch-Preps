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
    int solve(TreeNode* root) {
        if(!root) return 0;
        int lh = solve(root->left);
        if(lh == -1) return -1;
        int rh = solve(root->right);
        if(rh == -1) return -1;
        if(abs(lh - rh) > 1) return -1;
        return max(lh, rh) + 1;
    }
    bool isBalanced(TreeNode* root) {
        return solve(root) == -1 ? false : true;
    }
};
/*
class Solution {
public:
    int height(TreeNode* root) {
        if(!root) return 0;
        return 1 + max(height(root->left), height(root->right));
    }
    bool solve(TreeNode* root) {
        if(!root) return true;
        int lh = height(root->left);
        int rh = height(root->right);
        if(abs(lh - rh) > 1) return false;
        return solve(root->left) && solve(root->right);
    }
    bool isBalanced(TreeNode* root) {
        return solve(root);
    }
};
*/