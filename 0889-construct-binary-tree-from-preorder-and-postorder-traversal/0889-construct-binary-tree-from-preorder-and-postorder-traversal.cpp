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
    unordered_map<int,int>mp;
    TreeNode* constructFromPrePost(vector<int>& preorder, vector<int>& postorder) {
        int n = preorder.size();
        for(int i=0; i<n; i++) {
            mp[postorder[i]] = i;
        }
        return solve(preorder, 0, n-1, postorder, 0, n-1);
    }
    TreeNode* solve(vector<int>&preorder, int preS, int preE, vector<int>&postorder, int postS, int postE) {
        if(preS > preE) return NULL;
        TreeNode* cur = new TreeNode(preorder[preS]);
        if(preS == preE) return cur;
        int idx = mp[preorder[preS+1]];
        int len = idx-postS+1;
        cur->left = solve(preorder, preS+1, preS+len, postorder, postS, idx);
        cur->right = solve(preorder, preS+len+1, preE, postorder, idx+1, postE-1);
        return cur;
    }
};
// idx = 2-6 = 4