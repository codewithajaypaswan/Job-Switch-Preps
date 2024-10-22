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
    long long kthLargestLevelSum(TreeNode* root, int k) {
        vector<long long>v;
        queue<TreeNode*>q;
        q.push(root);
        while(!q.empty()) {
            int sz = q.size();
            long long sum = 0;
            while(sz--) {
                TreeNode* cur = q.front(); q.pop();
                sum += cur->val;
                if(cur->left) q.push(cur->left);
                if(cur->right) q.push(cur->right);
            }
            v.push_back(sum);
        }
        if(v.size() < k) return -1;
        sort(v.rbegin(), v.rend());
        for(int x:v) cout<<x<<" ";
        cout<<endl;
        return v[k-1];
    }
};