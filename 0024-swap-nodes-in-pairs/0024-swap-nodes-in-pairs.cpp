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
        if(!head || !head->next) return head;
        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        ListNode* prev = dummy, *cur = head;
        while(cur && cur->next) {
            ListNode* temp = cur->next;
            cur->next = temp->next;
            temp->next = cur;
            prev->next = temp;
            prev = cur;
            cur = cur->next;
        }
        return dummy->next;
    }
};