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
        ListNode temp = head;
        while(temp != null) {
            temp = temp.next;
            n++;
        }
        int[] ans = new int[n];
        Stack<Pair<Integer, Integer>>st = new Stack();
        temp = head;
        for(int i=0; i<n; i++) {
            while(!st.isEmpty() && st.peek().getKey() < temp.val) {
                ans[st.peek().getValue()] = temp.val;
                st.pop();
            }
            st.push(new Pair<>(temp.val, i));
            temp = temp.next;
        }
        return ans;
    }
}