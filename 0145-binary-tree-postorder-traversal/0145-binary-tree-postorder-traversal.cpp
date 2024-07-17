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
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int>ans;
        TreeNode* cur = root, *last = NULL;
        stack<TreeNode*>st;
        while(cur || !st.empty()) {
            if(cur) {
                st.push(cur);
                cur = cur->left;
            }
            else {
                TreeNode* node = st.top();
                if(node->right && node->right != last) {
                    cur = node->right;
                }
                else {
                    ans.push_back(node->val);
                    last = node;
                    st.pop();
                }
            }
        }
        return ans;
    }
};