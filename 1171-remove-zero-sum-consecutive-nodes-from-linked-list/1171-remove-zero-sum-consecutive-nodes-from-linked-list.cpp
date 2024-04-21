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
        if(!head) return head;
        unordered_map<int, ListNode*>mp;
        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        int sum = 0;
        mp[sum] = dummy;
        while(head) {
            sum += head->val;
            if(mp.find(sum) != mp.end()) {
                ListNode* prev = mp[sum];
                ListNode* start = prev;
                int temp_sum = sum;
                while(prev != head) {
                    prev = prev->next;
                    temp_sum += prev->val;
                    if(prev != head) mp.erase(temp_sum);
                }
                start->next = head->next;
            }
            else {
                mp[sum] = head;
            }
            head = head->next;
        }
        return dummy->next;
    }
};