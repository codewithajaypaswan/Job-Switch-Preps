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
    vector<int>ans;
    vector<int> preorderTraversal(TreeNode* root) {
        TreeNode* cur = root;
        stack<TreeNode*>st;
        while(!st.empty() || cur) {
            if(cur != NULL) {
                ans.push_back(cur->val);
                st.push(cur);
                cur = cur->left;
            }
            else {
                cur = st.top(); st.pop();
                cur = cur->right;
            }
        }
        return ans;
    }
};