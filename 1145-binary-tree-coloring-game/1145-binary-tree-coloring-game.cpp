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
    int leftChild = 0, rightChild = 0, parent = 0;
    bool btreeGameWinningMove(TreeNode* root, int n, int x) {
        n = count(root, x);
        parent = n - leftChild - rightChild - 1;
        int mx = max({leftChild, rightChild, parent});
        return mx > n/2;
    }
    int count(TreeNode* root, int x) {
        if(!root) return 0;
        int cntLeft = count(root->left, x);
        int cntRight = count(root->right, x);
        if(root->val == x) {
            leftChild = cntLeft;
            rightChild = cntRight;
        }
        return 1 + cntLeft + cntRight;
    }
};