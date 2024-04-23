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
    unordered_map<int, int>mp;
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int n = inorder.size();
        for(int i=0; i<n; i++) {
            mp[inorder[i]] = i;
        }
        return solve(preorder, 0, n-1);
    }
    TreeNode* solve(vector<int>&preorder, int low, int high) {
        if(low > high) return NULL;
        TreeNode* cur = new TreeNode(preorder[preInd]);
        int mid = mp[preorder[preInd]];
        preInd++;
        cur->left = solve(preorder, low, mid-1);
        cur->right = solve(preorder, mid+1, high);
        return cur;
    }
};