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
    vector<int>arr;
    void inorder(TreeNode* root) {
        if(!root) return;
        inorder(root->left);
        arr.push_back(root->val);
        inorder(root->right);
    }
    TreeNode* balanceBST(TreeNode* root) {
        inorder(root);
        return make_tree(arr, 0, arr.size()-1);
    }
    TreeNode* make_tree(vector<int>&arr, int low, int high) {
        if(low > high) return NULL;
        if(low == high) return new TreeNode(arr[low]);
        int mid = low + (high - low)/2;
        TreeNode* cur = new TreeNode(arr[mid]);
        cur->left = make_tree(arr, low, mid-1);
        cur->right = make_tree(arr, mid+1, high);
        return cur;
    }
};