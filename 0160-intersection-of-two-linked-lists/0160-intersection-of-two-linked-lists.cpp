/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    int count(ListNode* head) {
        int cnt = 0;
        while(head) {
            head = head->next;
            cnt++;
        }
        return cnt;
    }
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        int cnt1 = count(headA);
        int cnt2 = count(headB);
        if(cnt1 > cnt2) {
            while(headA && cnt1 > cnt2) {
                headA = headA->next;
                cnt1--;
            }
        }
        else if(cnt2 > cnt1) {
            while(headB && cnt2 > cnt1) {
                headB = headB->next;
                cnt2--;
            }
        }
        while(headA != headB) {
            headA = headA->next;
            headB = headB->next;
        }
        return headA;
    }
};