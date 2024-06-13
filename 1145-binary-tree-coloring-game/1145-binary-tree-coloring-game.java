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
    int leftChild = 0, rightChild = 0, parent = 0;
    public boolean btreeGameWinningMove(TreeNode root, int n, int x) {
        n = count(root, x);
        parent = n - leftChild - rightChild - 1;
        int mx = Math.max(Math.max(leftChild, rightChild), parent);
        return mx > n/2;
    }
    int count(TreeNode root, int x) {
        if(root == null) return 0;
        int cntLeft = count(root.left, x);
        int cntRight = count(root.right, x); 
        if(root.val == x) {
            leftChild = cntLeft;
            rightChild = cntRight;
        }
        return 1 + cntLeft + cntRight;
    }
}