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
    public int numComponents(ListNode head, int[] nums) {
        Set<Integer>st = new HashSet<>();
        for(int x:nums) {
            st.add(x);
        }
        int flag = 0, ans = 0;
        while(head != null) {
            if(st.contains(head.val)) {
                flag = 1;
            }
            else {
                ans += flag;
                flag = 0;
            }
            head = head.next;
        }
        ans += flag;
        return ans;
    }
}