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
    int ans = 0;
    vector<int> dfs(TreeNode* root, int dist) {
        if(!root) return {};
        if(!root->left && !root->right) return {1};
        vector<int>leftLeaf = dfs(root->left, dist);
        vector<int>rightLeaf = dfs(root->right, dist);
        for(int l:leftLeaf) {
            for(int r:rightLeaf) {
                if(l+r <= dist) ans++;
            }
        }
        vector<int>overAllLeaf;
        for(int l:leftLeaf) overAllLeaf.push_back(l+1);
        for(int r:rightLeaf) overAllLeaf.push_back(r+1);
        return overAllLeaf;
    }
    int countPairs(TreeNode* root, int distance) {
        dfs(root, distance);
        return ans;
    }
};