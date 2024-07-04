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
    ListNode* mergeNodes(ListNode* head) {
        ListNode *temp, *cur = head;
        ListNode* dummy = new ListNode(0);
        temp = dummy;
        while(cur->next) {
            int sum = 0;
            while(cur->next->val != 0) {
                sum += cur->next->val;
                cur = cur->next;
            }
            cur = cur->next;
            temp->next = new ListNode(sum);
            temp = temp->next;
        }
        return dummy->next;
    }
};