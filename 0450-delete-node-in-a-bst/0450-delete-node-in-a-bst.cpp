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
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(!root) return root;
        if(root->val == key) return del(root);
        TreeNode* cur = root;
        while(cur) {
            if(cur->val < key) {
                if(cur->right && cur->right->val == key) {
                    cur->right = del(cur->right);
                    return root;
                }
                cur = cur->right;
            }
            else {
                if(cur->left && cur->left->val == key) {
                    cur->left = del(cur->left);
                    return root;
                }
                cur = cur->left;
            }
        }
        return root;
    }
    
    TreeNode* findLeftMost(TreeNode* root) {
        while(root->left != NULL) {
            root = root->left;
        } 
        return root;
    }
    TreeNode* del(TreeNode* root) {
        if(!root->left && !root->right) return NULL;
        if(!root->left) return root->right;
        if(!root->right) return root->left;
        TreeNode* p1 = root->left;
        TreeNode* leftMost = findLeftMost(root->right);
        leftMost->left = p1;
        return root->right;
    }
};