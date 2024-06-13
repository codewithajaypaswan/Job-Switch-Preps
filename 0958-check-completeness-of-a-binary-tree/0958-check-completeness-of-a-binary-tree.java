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
    long count = 0, sum = 0;
    public boolean isCompleteTree(TreeNode root) {
        // solve(root, 1);
        // return (count * (count + 1)/2) == sum;
        Queue<TreeNode> q = new LinkedList<>();
        boolean flag = false;
        q.add(root);
        while(!q.isEmpty()) {
            TreeNode cur = q.poll();
            if(cur == null) {
                flag = true;
            }
            else {
                if(flag == true) return false;
                q.add(cur.left);
                q.add(cur.right);
            }
        }
        return true;
    }
    private void solve(TreeNode root, long label) {
        if(root == null) return;
        count++;
        sum += label;
        solve(root.left, label * 2);
        solve(root.right, label * 2 + 1);
    }
}