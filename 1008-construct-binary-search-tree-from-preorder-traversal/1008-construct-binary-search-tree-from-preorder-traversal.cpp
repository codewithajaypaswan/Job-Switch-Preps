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
    int preInd = 0;
    TreeNode* solve(vector<int>&preorder, int low, int high) {
        if(preInd >= preorder.size() || preorder[preInd] < low || preorder[preInd] > high) return NULL;
        TreeNode* cur = new TreeNode(preorder[preInd++]);
        cur->left = solve(preorder, low, cur->val);
        cur->right = solve(preorder, cur->val, high);
        return cur;
    }
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        return solve(preorder, INT_MIN, INT_MAX);
    }
};