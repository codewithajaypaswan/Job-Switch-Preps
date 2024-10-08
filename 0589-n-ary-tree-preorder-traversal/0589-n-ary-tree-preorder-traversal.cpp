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
    vector<int> preorder(Node* root) {
        vector<int>ans;
        stack<Node*>st;
        if(!root) return ans;
        st.push(root);
        while(!st.empty()) {
            Node* cur = st.top(); st.pop();
            ans.push_back(cur->val);
            for(int i=cur->children.size() - 1; i>=0; i--) {
                st.push(cur->children[i]);
            }
        }
        return ans;
    }
};

/*

class Solution {
public:
    vector<int>ans;
    void dfs(Node* root) {
        if(root == NULL) return;
        ans.push_back(root->val);
        for(int i=0; i<root->children.size(); i++) {
            dfs(root->children[i]);
        }
        return;
    }
    vector<int> preorder(Node* root) {
        dfs(root);
        return ans;
    }
};

*/