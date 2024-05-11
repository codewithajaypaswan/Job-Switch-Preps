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
/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode() {}
 *     TreeNode(int val) { this.val = val; }
 *     TreeNode(int val, TreeNode left, TreeNode right) {
 *         this.val = val;
 *         this.left = left;
 *         this.right = right;
 *     }
 * }
 */
class Solution {
    TreeNode solve(ListNode head, ListNode tail) {
        if(head == tail) return null;
        if(head.next == tail) return new TreeNode(head.val);
        ListNode fast = head.next, slow = head;
        while(fast != tail && fast.next != tail) {
            fast = fast.next.next;
            slow = slow.next;
        }
        TreeNode cur = new TreeNode(slow.val);
        cur.left = solve(head, slow);
        cur.right = solve(slow.next, tail);
        return cur;
    }
    public TreeNode sortedListToBST(ListNode head) {
        return solve(head, null);
    }
}