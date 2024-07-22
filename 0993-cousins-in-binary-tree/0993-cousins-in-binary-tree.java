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
    TreeNode xParent = null, yParent = null;
    int xHeight = 0, yHeight = 0;
    public boolean isCousins(TreeNode root, int x, int y) {
        solve(root, x, y, null, 0);
        return xHeight == yHeight && xParent.val != yParent.val;
    }
    void solve(TreeNode root, int x, int y, TreeNode parent, int depth) {
        if(root == null) return;
        if(root.val == x) {
            xParent = parent;
            xHeight = depth;
        }
        if(root.val == y) {
            yParent = parent;
            yHeight = depth;
        }
        solve(root.left, x, y, root, depth+1);
        solve(root.right, x, y, root, depth+1);
    }
}