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
    TreeNode cur = new TreeNode(0);
    TreeNode dummy = cur;
    void solve(TreeNode root) {
        if(root == null) return;
        solve(root.left);
        cur.right = new TreeNode(root.val);
        cur = cur.right;
        solve(root.right);
    }
    public TreeNode increasingBST(TreeNode root) {
        solve(root);
        return dummy.right;
    }
}