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
    public ListNode solve(ListNode head) {
        if(head.next == null) return head;
        ListNode temp = solve(head.next);
        head.next.next = head;
        return temp;
    }
    public ListNode reverseList(ListNode head) {
        if(head == null) return head;
        ListNode temp = head;
        head = solve(head);
        temp.next = null;
        return head;
    }
}
