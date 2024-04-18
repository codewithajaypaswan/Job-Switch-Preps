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
    vector<int> postorder(Node* root) {
        vector<int>ans;
        stack<Node*>st;
        if(!root) return ans;
        st.push(root);
        while(!st.empty()) {
            Node* cur = st.top(); st.pop();
            ans.push_back(cur->val);
            for(int i=0; i<cur->children.size(); i++) {
                st.push(cur->children[i]);
            }
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};