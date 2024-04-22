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
    int xDepth = -1, yDepth = -2;
    TreeNode* xParent = NULL, *yParent = NULL;
    void dfs(TreeNode* root, int x, int y, TreeNode* parent, int depth) {
        if(!root) return;
        if(root->val == x) {
            xParent = parent;
            xDepth = depth;
        }
        if(root->val == y) {
            yParent = parent;
            yDepth = depth;
        }
        dfs(root->left, x, y, root, depth + 1);
        dfs(root->right, x, y, root, depth + 1);
    }
    bool isCousins(TreeNode* root, int x, int y) {
        dfs(root, x, y, NULL, 0);
        return xDepth == yDepth && xParent != yParent;
    }
};