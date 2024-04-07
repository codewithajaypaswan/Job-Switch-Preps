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
    ListNode* swapPairs(ListNode* head) {
        if(!head) return head;
        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        ListNode* cur = head, *prev = dummy;
        while(cur && cur->next) {
            ListNode* temp = cur->next;
            cur->next = cur->next->next;
            temp->next = prev->next;
            prev->next = temp;
            prev = cur;
            cur = cur->next;
        }
        return dummy->next;
    }
};