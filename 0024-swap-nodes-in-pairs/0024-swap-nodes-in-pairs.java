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
    public ListNode swapPairs(ListNode head) {
        if(head == null || head.next == null) return head;
        ListNode dummy = new ListNode(0);
        dummy.next = head;
        ListNode cur = head, prev = dummy;
        while(cur != null && cur.next != null) {
            ListNode temp = cur.next;
            cur.next = temp.next;
            temp.next = cur;
            prev.next = temp;
            prev = cur;
            cur = cur.next;
        }
        return dummy.next;
    }
}