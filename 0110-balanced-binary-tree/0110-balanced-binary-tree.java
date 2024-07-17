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
    public int solve(TreeNode root) {
        if(root == null) return 0;
        int lh = solve(root.left);
        if(lh == -1) return -1;
        int rh = solve(root.right);
        if(rh == -1) return -1;
        if(Math.abs(lh - rh) > 1) return -1;
        return Math.max(solve(root.left), solve(root.right)) + 1;
    }
    public boolean isBalanced(TreeNode root) {
        return solve(root) == -1 ? false : true;
    }
}

/*

class Solution {
    public int height(TreeNode root) {
        if(root == null) return 0;
        return 1 + Math.max(height(root.left), height(root.right));
    }
    public boolean solve(TreeNode root) {
        if(root == null) return true;
        int lh = height(root.left);
        int rh = height(root.right);
        if(Math.abs(lh - rh) > 1) return false;
        return solve(root.left) && solve(root.right);
    }
    public boolean isBalanced(TreeNode root) {
        return solve(root);
    }
}

*/