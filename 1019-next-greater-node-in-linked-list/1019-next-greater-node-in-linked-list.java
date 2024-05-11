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
    public int[] nextLargerNodes(ListNode head) {
        int n = 0;
        ListNode cur = head;
        while(cur != null) {
            n++;
            cur = cur.next;
        }
        int[] ans = new int[n];
        cur = head;
        Stack<Pair<Integer, Integer>>st = new Stack<>();
        for(int i=0; i<n; i++) {
            while(!st.isEmpty() && st.peek().getKey() < cur.val) {
                ans[st.peek().getValue()] = cur.val;
                st.pop();
            }
            st.push(new Pair<>(cur.val, i));
            cur = cur.next;
        }
        return ans;
    }
}