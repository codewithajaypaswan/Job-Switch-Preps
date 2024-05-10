/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int x) {
 *         val = x;
 *         next = null;
 *     }
 * }
 */
public class Solution {
    public ListNode getIntersectionNode(ListNode headA, ListNode headB) {
        int len1 = 0, len2 = 0;
        ListNode temp1 = headA, temp2 = headB;
        while(temp1 != null) {
            len1++;
            temp1 = temp1.next;
        }
        while(temp2 != null) {
            len2++;
            temp2 = temp2.next;
        }
        temp1 = headA;
        temp2 = headB;
        while(len1 > len2) {
            len1--;
            temp1 = temp1.next;
        }
        while(len1 < len2) {
            len2--;
            temp2 = temp2.next;
        }
        while(temp1 != temp2) {
            temp1 = temp1.next;
            temp2 = temp2.next;
        }
        return temp1;
    }
}