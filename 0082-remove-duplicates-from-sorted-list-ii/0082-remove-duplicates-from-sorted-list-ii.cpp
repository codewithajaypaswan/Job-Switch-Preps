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
        ListNode* dummy = new ListNode(0);
        ListNode* prev = dummy, *cur = head;
        dummy->next = head;
        while(cur) {
            while(cur->next && cur->next->val == cur->val) cur = cur->next;
            if(prev->next == cur) {
                prev = cur;
                cur = cur->next;
            }
            else {
                cur = cur->next;
                prev->next = cur;
            }
        }
        return dummy->next;
    }
};