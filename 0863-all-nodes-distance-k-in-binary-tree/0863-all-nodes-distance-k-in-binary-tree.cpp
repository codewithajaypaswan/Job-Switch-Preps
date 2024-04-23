/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    unordered_map<TreeNode*, TreeNode*>parent;
    unordered_map<TreeNode*, bool>vis;
    void markParent(TreeNode* root, TreeNode* p) {
        if(!root) return;
        if(p != NULL) parent[root] = p;
        markParent(root->left, root);
        markParent(root->right, root);
    }
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        markParent(root, NULL);
        vector<int>ans;
        queue<TreeNode*>q;
        int level = 0;
        q.push(target);
        vis[target] = true;
        while(!q.empty()) {
            if(level++ == k) break;
            int sz = q.size();
            while(sz--) {
                TreeNode* cur = q.front(); q.pop();
                if(cur->left && !vis[cur->left]) {
                    q.push(cur->left);
                    vis[cur->left] = true;
                }
                if(cur->right && !vis[cur->right]) {
                    q.push(cur->right);
                    vis[cur->right] = true;
                }
                if(parent[cur] && !vis[parent[cur]]) {
                    q.push(parent[cur]);
                    vis[parent[cur]] = true;
                }
            }
        }
        while(!q.empty()) {
            TreeNode* cur = q.front(); q.pop();
            ans.push_back(cur->val);
        }
        return ans;
    }
};