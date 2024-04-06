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
    int maxDepth(TreeNode* root) {
        if(!root) return 0;
        return max(maxDepth(root->left), maxDepth(root->right)) + 1;
    }
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        int depth = maxDepth(root);
        vector<vector<int>>ans(depth);
        queue<TreeNode*>q;
        if(!root) return ans;
        q.push(root);
        while(!q.empty()) {
            int size = q.size();
            depth--;
            for(int i=0; i<size; i++) {
                TreeNode* cur = q.front();
                q.pop();
                ans[depth].push_back(cur->val);
                if(cur->left) {
                    q.push(cur->left);
                }
                if(cur->right) {
                    q.push(cur->right);
                }
            }
        }
        return ans;
    }
};