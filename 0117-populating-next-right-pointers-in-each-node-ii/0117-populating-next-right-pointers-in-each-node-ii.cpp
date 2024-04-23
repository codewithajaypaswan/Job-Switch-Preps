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
    Node* connect(Node* root) {
        if(!root) return root;
        Node* head, *tail;
        head = tail = NULL;
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
};