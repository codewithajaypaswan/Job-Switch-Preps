/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    Node* solution1(Node* root) {
        Node* head = NULL, *tail = NULL;
        Node* cur = root;
        while(cur) {
            if(cur->left) {
                if(tail) {
                    tail->next = cur->left;
                    tail = tail->next;
                }
                else {
                    tail = cur->left;
                    head = tail;
                }
            }
            if(cur->right) {
                if(tail) {
                    tail->next = cur->right;
                    tail = tail->next;
                }
                else {
                    tail = cur->right;
                    head = tail;
                }
            }
            cur = cur->next;
            if(cur == NULL) {
                cur = head;
                head = tail = NULL;
            }
        }
        return root;
    }
    Node* connect(Node* root) {
        if(!root) return root;
        // return solution1(root);
        queue<Node*>q;
        q.push(root);
        q.push(NULL);
        while(!q.empty()) {
            Node* cur = q.front(); q.pop();
            if(cur == NULL && q.empty()) return root;
            else if(cur == NULL && !q.empty()) q.push(NULL);
            else {
                cur->next = q.front();
                if(cur->left) q.push(cur->left);
                if(cur->right) q.push(cur->right);
            }
        }
        return root;
    }
};