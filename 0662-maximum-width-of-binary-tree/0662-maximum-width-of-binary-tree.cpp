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
    int widthOfBinaryTree(TreeNode* root) {
        if(!root) return 0;
        queue<pair<TreeNode*, int>>q;
        q.push({root, 0});
        int ans = 0;
        while(!q.empty()) {
            int l = q.front().second;
            int r = l, sz = q.size();
            while(sz--) {
                auto it = q.front(); q.pop();
                TreeNode* cur = it.first;
                r = it.second;
                if(cur->left) {
                    q.push({cur->left, r * 2L + 1});
                }
                if(cur->right) {
                    q.push({cur->right, r * 2L + 2});
                }
            }
            ans = max(ans, r - l + 1);
        }
        return ans;
    }
};