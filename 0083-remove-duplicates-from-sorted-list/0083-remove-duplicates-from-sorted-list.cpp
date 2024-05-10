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
    ListNode* deleteDuplicates(ListNode* head) {
        if(!head) return head;
        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        ListNode* cur = head, *prev = dummy;
        while(cur) {
            while(cur && cur->next && cur->val == cur->next->val) cur = cur->next;
            if(prev->next == cur) {
                prev = prev->next;
            }
            else {
                prev->next = cur;
                prev = cur;
            }
            cur = cur->next;
        }
        return dummy->next;
    }
};