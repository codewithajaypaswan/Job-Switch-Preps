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
    unordered_map<long, int>mp;
    int ans = 0;
    int pathSum(TreeNode* root, int targetSum) {
        if(root && !root->left && !root->right) return root->val == targetSum;
        dfs(root, targetSum, 0);
        return ans;
    }
    void dfs(TreeNode* root, int targetSum, long sum) {
        if(!root) return;
        sum += root->val;
        if(sum == targetSum) ans++;
        if(mp.find(sum - targetSum) != mp.end()) {
            ans += mp[sum - targetSum];
        }
        mp[sum]++;
        dfs(root->left, targetSum, sum);
        dfs(root->right, targetSum, sum);
        mp[sum]--;
    }
};