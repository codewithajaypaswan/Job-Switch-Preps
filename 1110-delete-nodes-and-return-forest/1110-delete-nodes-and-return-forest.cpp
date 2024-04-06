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
    unordered_map<int, int>mp;
    vector<TreeNode*>ans;
    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {
        for(auto it:to_delete) {
            mp[it]++;
        }
        if(mp.find(root->val) == mp.end()) ans.push_back(root);
        dfs(root);
        return ans;
    }
    TreeNode* dfs(TreeNode* root) {
        if(!root) return NULL;
        root->left = dfs(root->left);
        root->right = dfs(root->right);
        if(mp.find(root->val) != mp.end()) {
            if(root->left && mp[root->left->val] == 0) ans.push_back(root->left);
            if(root->right && mp[root->right->val] == 0) ans.push_back(root->right);
            return NULL;
        }
        return root;
    }
};