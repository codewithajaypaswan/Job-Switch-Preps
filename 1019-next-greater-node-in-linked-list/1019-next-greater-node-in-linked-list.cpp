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
    vector<int> nextLargerNodes(ListNode* head) {
        int n = 0;
        ListNode* cur = head;
        while(cur) {
            n++;
            cur = cur->next;
        }
        vector<int>ans(n, 0);
        stack<pair<int, int>>st;
        cur = head;
        for(int i=0; i<n; i++) {
            while(!st.empty() && st.top().first < cur->val) {
                ans[st.top().second] = cur->val;
                st.pop();
            }
            st.push({cur->val, i});
            cur = cur->next;
        }
        return ans;
    }
};