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
    #define ll long long
    ll ans = 0, total = 0, mod = 1e9+7;
    ll dfs(TreeNode* root) {
        if(!root) return 0;
        ll sum = root->val + dfs(root->left) + dfs(root->right);
        ans = max(ans, (total - sum) * sum);
        return sum;
    }
    int maxProduct(TreeNode* root) {
        total = dfs(root);
        ans = 0;
        dfs(root);
        return ans%mod;
    }
};