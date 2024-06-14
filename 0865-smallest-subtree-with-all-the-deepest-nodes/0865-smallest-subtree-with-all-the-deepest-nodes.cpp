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
    TreeNode* ans = NULL;
    int maxDepth = -1;
    int dfs(TreeNode* root, int depth) {
        if(!root) return depth;
        int leftDepth = dfs(root->left, depth+1);
        int rightDepth = dfs(root->right, depth+1);
        if(leftDepth == rightDepth) {
            maxDepth = max(maxDepth, leftDepth);
            if(leftDepth == maxDepth) {
                ans = root;
            }
        }
        return max(leftDepth, rightDepth);
    }
    TreeNode* subtreeWithAllDeepest(TreeNode* root) {
        dfs(root, 0);
        return ans;
    }
};