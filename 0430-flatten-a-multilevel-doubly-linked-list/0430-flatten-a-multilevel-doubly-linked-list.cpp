/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;
};
*/

class Solution {
public:
    Node* flatten(Node* head) {
        Node * cur = head;
        while(cur) {
            if(cur->child == NULL) {
                cur = cur->next;
                continue;
            }
            Node* temp = cur->child;
            while(temp->next) {
                temp = temp->next;
            }
            temp->next = cur->next;
            if(cur->next) {
                cur->next->prev = temp;
            }
            cur->next = cur->child;
            cur->next->prev = cur;
            cur->child = NULL;
            cur = cur->next;
        }
        return head;
    }
};