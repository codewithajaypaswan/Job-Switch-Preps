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
    TreeNode* findLCA(TreeNode* root, int a, int b) {
        if(!root || (root->val == a || root->val == b)) return root;
        TreeNode* left = findLCA(root->left, a, b);
        TreeNode* right = findLCA(root->right, a, b);
        if(left && right) return root;
        return left ? left : right;
    }
    string left, right;
    bool getPath(TreeNode *root, int value, string &path) {
        if(!root) return false;
        if(root->val == value) return true;
        path += 'L';
        auto res = getPath(root->left, value, path);
        if(res) return true;
        path.pop_back();
        path += 'R';
        res = getPath(root->right, value, path);
        if(res) return true;
        path.pop_back();
        return false;
    }
    string getDirections(TreeNode* root, int startValue, int destValue) {
        left = "", right = "";
        TreeNode* ancestor = findLCA(root, startValue, destValue);
        getPath(ancestor, startValue, left);
        getPath(ancestor, destValue, right);
        for(char &c:left) c = 'U';
        return left+right;
    }
};