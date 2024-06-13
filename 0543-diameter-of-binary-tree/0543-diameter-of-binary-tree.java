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
    private void solve1(TreeNode root) {
        if(root == null) return;
        int lh = height(root.left);
        int rh = height(root.right);
        ans = Math.max(lh + rh, ans);
        solve1(root.left);
        solve1(root.right);
    }
    public int diameterOfBinaryTree(TreeNode root) {
        // solve1(root); // first solution
        solve2(root);
        return ans;
    }
    private int solve2(TreeNode root) {
        if(root == null) return 0;
        int lh = solve2(root.left);
        int rh = solve2(root.right);
        ans = Math.max(lh + rh, ans);
        return 1 + Math.max(lh, rh);
    }
}