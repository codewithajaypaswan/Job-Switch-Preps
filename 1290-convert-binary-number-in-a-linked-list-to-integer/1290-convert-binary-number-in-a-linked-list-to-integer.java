/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode() {}
 *     ListNode(int val) { this.val = val; }
 *     ListNode(int val, ListNode next) { this.val = val; this.next = next; }
 * }
 */
class Solution {
    public int getDecimalValue(ListNode head) {
        int ans = 0, len = 0;
        ListNode cur = head;
        while(cur != null) {
            cur = cur.next;
            len++;
        }
        cur = head;
        while(cur != null) {
            ans += (1<<(len-1)) * cur.val;
            cur = cur.next;
            len--;
        }
        return ans;
    }
}