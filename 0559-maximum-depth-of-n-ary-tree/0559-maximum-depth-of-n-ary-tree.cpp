/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    int ans = 0;
    void dfs(Node* root, int depth) {
        if(root == nullptr) return;
        if(root->children.size() == 0) {
            ans = max(ans, depth);
            return;
        }
        for(int i=0; i<root->children.size(); i++) {
            dfs(root->children[i], depth + 1);
        }
    }
    int maxDepth(Node* root) {
        dfs(root, 1);
        return ans;
    }
};