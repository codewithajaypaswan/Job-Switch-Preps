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
    void dfs(TreeNode* root, int val, int depth, int curDepth) {
        if(!root) return;
        
        if(curDepth == depth) {
            TreeNode* temp = root->left;
            root->left = new TreeNode(val);
            root->left->left = temp;
            
            temp = root->right;
            root->right = new TreeNode(val);
            root->right->right = temp;
        }
        dfs(root->left, val, depth, curDepth+1);
        dfs(root->right, val, depth, curDepth+1);
    }
    TreeNode* addOneRow(TreeNode* root, int val, int depth) {
        if(depth == 1) {
            TreeNode* cur = new TreeNode(val);
            cur->left = root;
            return cur;
        }
        dfs(root, val, depth - 2, 0);
        return root;
    }
};