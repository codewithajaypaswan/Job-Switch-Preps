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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if(!head) return NULL;
        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        ListNode* fast = dummy, *slow = dummy;
        for(int i=0; i<=n && fast; i++) {
            fast = fast->next;
        }
        while(fast) {
            fast = fast->next;
            slow = slow->next;
        }
        ListNode* temp = slow->next;
        slow->next = temp->next;
        temp->next = nullptr;
        delete temp;
        return dummy->next;
    }
};