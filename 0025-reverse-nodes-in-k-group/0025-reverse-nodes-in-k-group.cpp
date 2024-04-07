/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* reverse(ListNode* head, ListNode* tail) {
        ListNode* cur = head, *prev = tail;
        while(cur != tail) {
            ListNode* next = cur->next;
            cur->next = prev;
            prev = cur;
            cur = next;
        }
        return prev;
    }
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* node = head;
        for(int i=0; i<k; i++) {
            if(!node) return head;
            node = node->next;
        }
        ListNode* newHead = reverse(head, node);
        head->next = reverseKGroup(node, k);
        return newHead;
    }
};