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
    void reorderList(ListNode* head) {
        if(!head || !head->next) return;
        ListNode* fast = head, *slow = head, *prev = NULL;
        while(fast && fast->next) {
            prev = slow;
            fast = fast->next->next;
            slow = slow->next;
        }
        if(prev) {
            prev->next = NULL;
        }
        slow = reverse(slow);
        head = merge(head, slow);
    }
    
    ListNode* merge(ListNode* p1, ListNode*p2) {
        ListNode* dummy = new ListNode(0);
        ListNode* cur = dummy;
        int cnt = 0;
        while(p1 && p2) {
            if(cnt%2 == 0) {
                cur->next = p1;
                p1 = p1->next;
            }
            else {
                cur->next = p2;
                p2 = p2->next;
            }
            cur = cur->next;
            cnt++;
        }
        cur->next = p1 ? p1 : p2;
        return dummy->next;
    }
    
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
};