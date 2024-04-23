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
class BSTIterator {
public:
    stack<TreeNode*>st;
    void pushLeft(TreeNode* root) {
        while(root) {
            st.push(root);
            root = root->left;
        }
    }
    BSTIterator(TreeNode* root) {
        pushLeft(root);
    }
    
    int next() {
        int val;
        if(!st.empty()) {
            TreeNode* cur = st.top(); st.pop();
            pushLeft(cur->right);
            val = cur->val;
        }
        return val;
    }
    
    bool hasNext() {
        return !st.empty();
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */