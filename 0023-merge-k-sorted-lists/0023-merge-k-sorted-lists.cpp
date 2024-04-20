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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* dummy = new ListNode(0);
        ListNode* head = dummy;
        while(list1 && list2) {
            if(list1->val < list2->val) {
                head->next = list1;
                list1 = list1->next;
            }
            else {
                head->next = list2;
                list2 = list2->next;
            }
            head = head->next;
        }
        head->next = list1 ? list1 : list2;
        return dummy->next;
    }
    ListNode* solve(vector<ListNode*>&lists, int cur) {
        if(cur == lists.size() - 1) return lists[cur];
        ListNode* a = solve(lists, cur+1);
        ListNode* b = lists[cur];
        a = mergeTwoLists(a, b);
        return a;
    }
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(lists.size() == 0) return NULL;
        return solve(lists, 0);
    }
};