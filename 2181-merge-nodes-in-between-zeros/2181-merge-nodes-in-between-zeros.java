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
    public ListNode mergeNodes(ListNode head) {
        ListNode cur = head;
        ListNode dummy = new ListNode(0);
        ListNode temp = dummy;
        while(cur.next != null) {
            int sum = 0;
            while(cur.next.val != 0) {
                sum += cur.next.val;
                cur = cur.next;
            }
            temp.next = new ListNode(sum);
            temp = temp.next;
            cur = cur.next;
        }
        return dummy.next;
    }
}