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
    ListNode* rotateRight(ListNode* head, int k) {
        if(!head || !head->next) return head;
        int len = 1;
        ListNode* cur = head;
        while(cur->next) {
            cur = cur->next;
            len++;
        }
        k = k%len;
        cur->next = head;
        cur = head;
        for(int i=0; i<len - k - 1; i++) {
            cur = cur->next;
        }
        head = cur->next;
        cur->next = NULL;
        return head;
    }
};