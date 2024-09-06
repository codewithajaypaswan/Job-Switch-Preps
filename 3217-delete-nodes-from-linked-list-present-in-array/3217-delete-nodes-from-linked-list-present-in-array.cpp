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
    ListNode* modifiedList(vector<int>& nums, ListNode* head) {
        vector<int>ans;
        ListNode* cur = head;
        unordered_set<int>st(nums.begin(), nums.end());
        while(cur) {
            if(!st.count(cur->val)) {
                ans.push_back(cur->val);
            }
            cur = cur->next;
        }
        ListNode* dummy = new ListNode(0);
        cur = dummy;
        for(int x:ans) {
            cur->next = new ListNode(x);
            cur = cur->next;
        }
        return dummy->next;
    }
};