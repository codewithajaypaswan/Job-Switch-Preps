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
    public ListNode deleteDuplicates(ListNode head) {
        ListNode dummy = new ListNode(0);
        dummy.next = head;
        ListNode cur = head, prev = dummy;
        while(cur != null) {
            while(cur != null && cur.next != null && cur.val == cur.next.val) {
                cur = cur.next;
            }
            if(prev.next == cur) {
                prev = prev.next;
            }
            else {
                prev.next = cur;
                prev = cur;
            }
            cur = cur.next;
        }
        return dummy.next;
    }
}