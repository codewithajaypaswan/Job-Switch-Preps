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
    public ListNode[] splitListToParts(ListNode head, int k) {
        ListNode[] ans = new ListNode[k];
        int len = 0;
        ListNode cur = head;
        while(cur != null) {
            cur = cur.next;
            len++;
        }
        int equal = len/k, rem = len%k;
        for(int i=0; i<k; i++, rem--) {
            ans[i] = head;
            ListNode prev = null;
            for(int j=0; j<equal + ((rem > 0) ? 1 : 0); j++) {
                prev = head;
                head = head.next;
            }
            if(prev != null) prev.next = null;
        }
        return ans;
    }
}