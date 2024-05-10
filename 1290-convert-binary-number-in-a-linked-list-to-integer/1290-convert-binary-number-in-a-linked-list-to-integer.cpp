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
    int getDecimalValue(ListNode* head) {
        ListNode* cur = head;
        int len = 0;
        while(cur) {
            cur = cur->next;
            len++;
        }
        int ans = 0;
        cur = head;
        while(cur) {
            ans += (1<<(len - 1)) * cur->val;
            len--;
            cur = cur->next;
        }
        return ans;
    }
};