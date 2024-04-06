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
    unsigned long long sum = 0, count = 0;
    bool isCompleteTree(TreeNode* root) {
        dfs(root, 1LL);
        return (count * (count + 1))/2 == sum;
    }
    void dfs(TreeNode* root, unsigned long long label) {
        if(!root) return;
        sum += label;
        count++;
        dfs(root->left, label * 2);
        dfs(root->right, label * 2 + 1);
    }
};