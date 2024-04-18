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
    bool hasPathSum(TreeNode* root, int targetSum) {
        queue<pair<TreeNode*, int>>q;
        if(!root) return false;
        q.push({root, targetSum});
        while(!q.empty()) {
            auto it = q.front(); q.pop();
            TreeNode* cur = it.first; 
            int val = it.second;
            if(!cur->left && !cur->right && cur->val == val) return true;
            if(cur->left) {
                q.push({cur->left, val - cur->val});
            }
            if(cur->right) {
                q.push({cur->right, val - cur->val});
            }
        }
        return false;
    }
};