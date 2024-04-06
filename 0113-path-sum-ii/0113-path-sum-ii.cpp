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
    void dfs(TreeNode* root, vector<int>temp, int targetSum) {
        if(!root) return;
        temp.push_back(root->val);
        if(!root->left && !root->right && root->val == targetSum) {
            ans.push_back(temp);
        }
        dfs(root->left, temp, targetSum - root->val);
        dfs(root->right, temp, targetSum - root->val);
    }
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<int>temp;
        dfs(root, temp, targetSum);
        return ans;
    }
};