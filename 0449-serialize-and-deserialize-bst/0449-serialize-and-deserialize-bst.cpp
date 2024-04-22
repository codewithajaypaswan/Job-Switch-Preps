/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

    // Encodes a tree to a single string.
    string ans = "";
    void serialize_tree(TreeNode* root) {
        if(!root) return;
        ans += to_string(root->val) + " ";
        serialize_tree(root->left);
        serialize_tree(root->right);
    }
    string serialize(TreeNode* root) {
        serialize_tree(root);
        return ans;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize_tree(queue<int>&q, int low, int high) {
        if(q.empty()) return NULL;
        int val = q.front();
        if(val > high || val < low) return NULL;
        q.pop();
        TreeNode* cur = new TreeNode(val);
        cur->left = deserialize_tree(q, low, val);
        cur->right = deserialize_tree(q, val, high);
        return cur;
    }
    TreeNode* deserialize(string data) {
        istringstream ss(data);
        queue<int>q;
        string s;
        while(ss >> s) q.push(stoi(s));
        return deserialize_tree(q, INT_MIN, INT_MAX);
    }
};

// Your Codec object will be instantiated and called as such:
// Codec* ser = new Codec();
// Codec* deser = new Codec();
// string tree = ser->serialize(root);
// TreeNode* ans = deser->deserialize(tree);
// return ans;