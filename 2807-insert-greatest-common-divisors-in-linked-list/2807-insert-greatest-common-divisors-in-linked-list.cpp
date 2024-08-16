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
    int gcd(int a, int b) {
        if(b == 0) return a;
        if(a == 0) return b;
        if(a > b) return gcd(a-b, b);
        return gcd(a, b-a);
    }
    ListNode* insertGreatestCommonDivisors(ListNode* head) {
        if(!head || !head->next) return head;
        ListNode* prev = head, *cur = head->next;
        while(cur != NULL) {
            int val = gcd(prev->val, cur->val);
            ListNode* next = prev->next;
            prev->next = new ListNode(val);
            prev->next->next = cur;
            prev = cur;
            cur = cur->next;
        }
        return head;
    }
};