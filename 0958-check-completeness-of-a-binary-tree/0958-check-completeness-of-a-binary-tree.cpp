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
    unsigned long long sum = 0, count = 0;
    bool isCompleteTree(TreeNode* root) {
        queue<TreeNode*>q;
        q.push(root);
        bool flag = false;
        while(!q.empty()) {
            TreeNode* cur = q.front(); q.pop();
            if(cur == NULL) {
                flag = true;
            }
            else {
                if(flag == true) return false;
                q.push(cur->left);
                q.push(cur->right);
            }
        }
        return true;
        // solve(root, 1LL);
        // return count * (count + 1)/2 == sum;
    }
    void solve(TreeNode* root, unsigned long long v) {
        if(!root) return;
        count++;
        sum += v;
        solve(root->left, v * 2);
        solve(root->right, v*2 + 1);
    }
};