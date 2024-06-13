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
    int ans = 0;
    private int height(TreeNode root) {
        if(root == null) return 0;
        return 1 + Math.max(height(root.left), height(root.right));
    }
    private void solve(TreeNode root) {
        if(root == null) return;
        int lh = height(root.left);
        int rh = height(root.right);
        ans = Math.max(lh + rh, ans);
        solve(root.left);
        solve(root.right);
    }
    public int diameterOfBinaryTree(TreeNode root) {
        solve(root);
        return ans;
    }
}