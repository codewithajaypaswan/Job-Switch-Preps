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
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        vector<ListNode*>ans(k, NULL);
        int len = 0;
        ListNode* cur = head;
        while(cur) {
            len++;
            cur = cur->next;
        }
        int equal = len/k, rem = len%k;
        for(int i=0; i<k; i++, rem--) {
            ans[i] = head;
            ListNode* prev = NULL;
            for(int j=0; j<equal + (rem > 0); j++) {
                prev = head;
                head = head->next;
            }
            if(prev) prev->next = NULL;
        }
        return ans;
    }
};