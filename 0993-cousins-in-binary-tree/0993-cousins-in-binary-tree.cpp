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
    int xDepth = -1, yDepth = -1;
    void dfs(TreeNode* root, int x, int y, int depth, TreeNode* parent) {
        if(!root) return;
        if(root->val == x) {
            xDepth = depth;
            xParent = parent;
        }
        if(root->val == y) {
            yDepth = depth;
            yParent = parent;
        }
        dfs(root->left, x, y, depth + 1, root);
        dfs(root->right, x, y, depth + 1, root);
    }
    TreeNode* xParent = NULL, *yParent = NULL;
    bool isCousins(TreeNode* root, int x, int y) {
        dfs(root, x, y, 0, NULL);
        return xDepth == yDepth && xParent != yParent;
    }
};