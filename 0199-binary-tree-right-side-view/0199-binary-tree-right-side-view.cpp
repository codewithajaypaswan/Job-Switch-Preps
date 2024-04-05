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
    vector<int> rightSideView(TreeNode* root) {
        vector<int>ans;
        queue<TreeNode*>q;
        if(root == NULL) return ans;
        q.push(root);
        while(!q.empty()) {
            int sz = q.size();
            for(int i=0; i<sz; i++) {
                TreeNode* cur = q.front(); q.pop();
                if(i == 0) ans.push_back(cur->val);
                if(cur->right) q.push(cur->right);
                if(cur->left) q.push(cur->left);
            }
        }
        return ans;
    }
};