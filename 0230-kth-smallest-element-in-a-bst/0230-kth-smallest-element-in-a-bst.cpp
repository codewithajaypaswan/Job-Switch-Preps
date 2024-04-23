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
class TreeWithCount {
public:
    int cnt, val;
    TreeWithCount *left, *right;
    TreeWithCount(int x) {
        val = x;
        cnt = 0;
        left = right = NULL;
    }
};

class Solution {
public:
    int count = 1;
    TreeWithCount* build(TreeNode* root) {
        if(!root) return NULL;
        TreeWithCount* cur = new TreeWithCount(root->val);
        cur->left = build(root->left);
        cur->cnt = count++;
        cur->right = build(root->right);
        return cur;

    }
    int kthSmallest(TreeNode* root, int k) {
        TreeWithCount* cur = build(root);
        while(cur) {
            if(cur->cnt == k) return cur->val;
            else if(cur->cnt > k) {
                cur = cur->left;
            }
            else {
                cur = cur->right;
            }
        }
        return -1;
    }
};