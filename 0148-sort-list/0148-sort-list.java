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
    ListNode merge(ListNode l1, ListNode l2) {
        ListNode dummy = new ListNode(0);
        ListNode cur = dummy;
        while(l1 != null && l2 != null) {
            if(l1.val < l2.val) {
                cur.next = l1;
                l1 = l1.next;
            }
            else {
                cur.next = l2;
                l2 = l2.next;
            }
            cur = cur.next;
        }
        cur.next = l1 != null ? l1 : l2;
        return dummy.next;
    }
    ListNode findMid(ListNode head) {
        if(head == null || head.next == null) return head;
        ListNode fast = head.next, slow = head;
        while(fast != null && fast.next != null) {
            fast = fast.next.next;
            slow = slow.next;
        }
        return slow;
    }
    ListNode mergeSort(ListNode head) {
        if(head == null || head.next == null) return head;
        ListNode a = head;
        ListNode mid = findMid(head);
        ListNode b = mid.next;
        mid.next = null;
        a = mergeSort(a);
        b = mergeSort(b);
        head = merge(a, b);
        return head;
    }
    public ListNode sortList(ListNode head) {
        return mergeSort(head);
    }
}