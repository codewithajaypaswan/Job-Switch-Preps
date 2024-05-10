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
    ListNode reverse(ListNode head, ListNode tail) {
        ListNode cur = head, prev = tail;
        while(cur != tail) {
            ListNode next = cur.next;
            cur.next = prev;
            prev = cur;
            cur = next;
        }
        return prev;
    }
    public ListNode reverseKGroup(ListNode head, int k) {
        if(head == null) return head;
        ListNode node = head;
        for(int i=0; i<k; i++) {
            if(node == null) return head;
            node = node.next;
        }
        ListNode newHead = reverse(head, node);
        head.next = reverseKGroup(node, k);
        return newHead;
    }
}