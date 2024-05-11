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
    ListNode* merge(ListNode* l1, ListNode* l2) {
        ListNode* dummy = new ListNode(0);
        ListNode* cur = dummy;
        while(l1 && l2) {
            if(l1->val < l2->val) {
                cur->next = l1;
                l1 = l1->next;
            }
            else {
                cur->next = l2;
                l2 = l2->next;
            }
            cur = cur->next;
        }
        cur->next = l1 ? l1 : l2;
        return dummy->next;
    }
    ListNode* findMid(ListNode* head) {
        if(!head || !head->next) return head;
        ListNode* fast = head->next, *slow = head;
        while(fast && fast->next) {
            fast = fast->next->next;
            slow = slow->next;
        }
        return slow;
    }
    ListNode* mergeSort(ListNode* head) {
        if(!head || !head->next) return head;
        ListNode* mid = findMid(head);
        ListNode* b = mid->next;
        mid->next = NULL;
        ListNode* a = head;
        a = mergeSort(a);
        b = mergeSort(b);
        head = merge(a, b);
        return head;
    }
    ListNode* sortList(ListNode* head) {
        return mergeSort(head);
    }
};