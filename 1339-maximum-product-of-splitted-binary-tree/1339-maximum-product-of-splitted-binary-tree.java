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
    long ans = 0, total = 0, mod = 1_000_000_007;
    long dfs(TreeNode root) {
        if(root == null) return 0;
        long sum = root.val + dfs(root.left) + dfs(root.right);
        ans = Math.max(ans, (total - sum) * sum);
        return sum;
    }
    public int maxProduct(TreeNode root) {
        total = dfs(root);
        ans = 0;
        dfs(root);
        return (int) (ans%mod);
    }
}