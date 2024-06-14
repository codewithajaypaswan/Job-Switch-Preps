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
    public boolean hasPathSum(TreeNode root, int targetSum) {
        if(root == null) return false;
        Queue<Pair<TreeNode, Integer>>q = new LinkedList<>();
        q.add(new Pair<>(root, targetSum));
        while(!q.isEmpty()) {
            int sz = q.size();
            while(sz-- > 0) {
                Pair<TreeNode, Integer> p = q.poll();
                TreeNode cur = p.getKey();
                int target = p.getValue();
                if(cur.left == null && cur.right == null && cur.val == target) return true;
                if(cur.left != null) {
                    q.add(new Pair<>(cur.left, target - cur.val));
                }
                if(cur.right != null) {
                    q.add(new Pair<>(cur.right, target - cur.val));
                }
            }
        }
        return false;
    }
}