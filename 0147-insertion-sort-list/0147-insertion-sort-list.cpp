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
    ListNode* insertionSortList(ListNode* head) {
        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        ListNode* cur = head, *prev = dummy;
        while(cur) {
            if(cur->next && (cur->next->val < cur->val)) {
                // insert a number in sorted order
                while(prev->next && prev->next->val < cur->next->val) {
                    prev = prev->next;
                }
                ListNode* temp = prev->next;
                prev->next = cur->next;
                cur->next = cur->next->next;
                prev->next->next = temp;
                prev = dummy;
            }
            else {
                cur = cur->next;
            }
        }
       return dummy->next;
    }
};