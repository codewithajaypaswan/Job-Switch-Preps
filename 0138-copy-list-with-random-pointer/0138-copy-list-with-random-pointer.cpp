/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if(!head) return head;
        Node* cur = head;
        while(cur) {
            Node* temp = new Node(cur->val);
            Node* next = cur->next;
            cur->next = temp;
            temp->next = next;
            cur = next;
        }
        cur = head;
        while(cur) {
            if(cur->random) {
                cur->next->random = cur->random->next;
            }
            cur = cur->next->next;
        }
        Node* dummy = new Node(0);
        Node* org = head, *dup = dummy;
        while(org) {
            dup->next = org->next;
            org->next = org->next->next;
            dup = dup->next;
            org = org->next;
        }
        return dummy->next;
    }
};