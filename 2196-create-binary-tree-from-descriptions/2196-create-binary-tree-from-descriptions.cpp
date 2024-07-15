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
    TreeNode* createBinaryTree(vector<vector<int>>& des) {
        unordered_map<int, TreeNode*>mp;
        unordered_map<int, bool>childrenFlag;
        for(auto d:des) {
            TreeNode* parent = new TreeNode(d[0]);
            TreeNode* child = new TreeNode(d[1]);
            if(!mp.count(d[0])) {
                mp[d[0]] = parent;
            }
            if(!mp.count(d[1])) {
                mp[d[1]] = child;
            }
            if(d[2] == 1) {
                mp[d[0]]->left = mp[d[1]];
            }
            if(d[2] == 0) {
                mp[d[0]]->right = mp[d[1]];
            }
            childrenFlag[d[1]] = true;
        }
        for(auto d:des) {
            if(!childrenFlag[d[0]]) return mp[d[0]];
        }
        return NULL;
    }
};