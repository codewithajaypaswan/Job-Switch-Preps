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
    ListNode* removeNodes(ListNode* head) {
        stack<ListNode*>st;
        ListNode* dummy = new ListNode(1e6);
        st.push(dummy);
        dummy->next = head;
        ListNode* cur = head;
        while(cur != NULL) {
            while(!st.empty() && st.top()->val < cur->val) {
                ListNode* temp = st.top(); st.pop();
                if(!st.empty()) st.top()->next = temp->next;
                temp->next = NULL;
                delete temp;
            }
            st.push(cur);
            cur = cur->next;
        }
        return dummy->next;
    }
};