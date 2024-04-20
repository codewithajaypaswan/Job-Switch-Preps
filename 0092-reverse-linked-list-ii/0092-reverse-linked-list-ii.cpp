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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        ListNode* prevLeft = dummy, *curLeft = head;
        for(int i=1; i<left; i++) {
            prevLeft = curLeft;
            curLeft = curLeft->next;
        }
        ListNode* prevRight = prevLeft, *curRight = curLeft;
        for(int i=left; i<=right; i++) {
            ListNode* nextRight = curRight->next;
            curRight->next = prevRight;
            prevRight = curRight;
            curRight = nextRight;
        }
        prevLeft->next = prevRight;
        curLeft->next = curRight;
        return dummy->next;
    }
};