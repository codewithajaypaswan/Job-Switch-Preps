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
    ListNode* removeZeroSumSublists(ListNode* head) {
        if(head == NULL) return head;
        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        unordered_map<int, ListNode*>mp;
        int sum = 0;
        mp[sum] = dummy;
        ListNode* cur = head;
        while(cur) {
            sum += cur->val;
            if(mp.find(sum) != mp.end()) {
                ListNode* prev = mp[sum];
                ListNode* start = prev;
                int temp_sum = sum;
                while(prev != cur) {
                    prev = prev->next;
                    temp_sum += prev->val;
                    if(prev != cur) mp.erase(temp_sum);
                }
                start->next = cur->next;
            }
            else {
                mp[sum] = cur;
            }
            cur = cur->next;
        }
        return dummy->next;
    }
};