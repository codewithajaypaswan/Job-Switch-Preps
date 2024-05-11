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
    public ListNode removeZeroSumSublists(ListNode head) {
        if(head == null) return null;
        ListNode dummy = new ListNode(0);
        dummy.next = head;
        Map<Integer, ListNode>mp = new HashMap<>();
        int sum = 0;
        mp.put(0, dummy);
        ListNode cur = head;
        while(cur != null) {
            sum += cur.val;
            if(mp.containsKey(sum)) {
                ListNode prev = mp.get(sum).next;
                System.out.println(sum);
                int temp_sum = sum + prev.val;
                while(temp_sum != sum) {
                    mp.remove(temp_sum);
                    prev = prev.next;
                    temp_sum += prev.val;
                }
                mp.get(sum).next = prev.next;
            }
            else {
                mp.put(sum, cur);
            }
            cur = cur.next;
        }
        return dummy.next;
    }
}