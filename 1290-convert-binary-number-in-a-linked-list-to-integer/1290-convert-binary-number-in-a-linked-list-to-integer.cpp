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
    ListNode* reverse(ListNode* head) {
        ListNode* cur = head, *prev = NULL;
        while(cur) {
            ListNode* next = cur->next;
            cur->next = prev;
            prev = cur;
            cur = next;
        }
        return prev;
    }
    int getDecimalValue(ListNode* head) {
        head = reverse(head);
        int ans = 0, i = 0;
        while(head) {
            ans += (1<<i) * head->val;
            i++;
            head = head->next;
        }
        return ans;
    }
};