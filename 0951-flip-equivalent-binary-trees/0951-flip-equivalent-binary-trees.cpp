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
    bool dfs(TreeNode* root1, TreeNode* root2) {
        if(root1 == NULL && root2 == NULL) return true;
        if(!root1 || !root2) return false;
        if(root1->val != root2->val) return false;
        bool noSwapLeft = dfs(root1->left, root2->left);
        bool noSwapRight = dfs(root1->right, root2->right);
        bool swapLeft = dfs(root1->left, root2->right);
        bool swapRight = dfs(root1->right, root2->left);
        return (noSwapLeft && noSwapRight) || (swapLeft && swapRight);
    }
    bool flipEquiv(TreeNode* root1, TreeNode* root2) {
        return dfs(root1, root2);
    }
};