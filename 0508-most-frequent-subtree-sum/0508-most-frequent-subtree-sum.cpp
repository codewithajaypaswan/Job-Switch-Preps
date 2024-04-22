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
    unordered_map<long long, int>mp;
    int mx = 0;
    long long dfs(TreeNode* root) {
        if(!root) return 0;
        long long sum = root->val + dfs(root->left) + dfs(root->right);
        mp[sum]++;
        mx = max(mx, mp[sum]);
        return sum;
    }
    vector<int> findFrequentTreeSum(TreeNode* root) {
        dfs(root);
        vector<int>ans;
        for(auto it:mp) {
            if(it.second == mx) {
                ans.push_back(it.first);
            }
        }
        return ans;
    }
};