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
    int numComponents(ListNode* head, vector<int>& nums) {
        int ans = 0;
        unordered_set<int>st(nums.begin(), nums.end());
        while(head) {
            if(st.count(head->val) && (head->next == NULL || st.find(head->next->val) == st.end())) ans++;
            head = head->next;
        }
        return ans;
    }
};