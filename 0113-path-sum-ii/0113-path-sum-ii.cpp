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
    vector<vector<int>>ans;
    void dfs(TreeNode* root, int targetSum, vector<int>temp) {
        if(!root) return;
        temp.push_back(root->val);
        if(!root->left && !root->right && root->val == targetSum) {
            ans.push_back(temp);
        }
        dfs(root->left, targetSum - root->val, temp);
        dfs(root->right, targetSum - root->val, temp);
        temp.pop_back();
    }
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<int>temp;
        dfs(root, targetSum, temp);
        return ans;
    }
};