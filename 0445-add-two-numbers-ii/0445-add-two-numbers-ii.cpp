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
    ListNode* reverse(ListNode* root) {
        ListNode* prev = NULL, *cur = root;
        while(cur) {
            ListNode* next = cur->next;
            cur->next = prev;
            prev = cur;
            cur = next;
        }
        return prev;
    }
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        l1 = reverse(l1);
        l2 = reverse(l2);
        ListNode* head = NULL, *tail = NULL;
        int carry = 0;
        while(l1 || l2) {
            int v1 = l1 != NULL ? l1->val : 0;
            int v2 = l2 != NULL ? l2->val : 0;
            int val = (v1 + v2 + carry);
            carry = val/10;
            ListNode* cur = new ListNode((val)%10);
            if(head == NULL) {
                head = tail = cur;
            }
            else {
                tail->next = cur;
                tail = tail->next;
            }
            l1 = l1 != NULL ? l1->next : NULL;
            l2 = l2 != NULL ? l2->next : NULL;
        }
        if(carry) {
            tail->next = new ListNode(carry);
        }
        return reverse(head);
    }
};