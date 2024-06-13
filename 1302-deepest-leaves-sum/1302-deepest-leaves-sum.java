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
    int maxDepth = 0;
    int findDepth(TreeNode root) {
        if(root == null) return 0;
        return Math.max(findDepth(root.left), findDepth(root.right)) + 1;
    }
    public int solve(TreeNode root, int depth) {
        if(root == null) return 0;
        if(depth == maxDepth) return root.val;
        return solve(root.left, depth+1) + solve(root.right, depth+1);
    }
    public int deepestLeavesSum(TreeNode root) {
        // maxDepth = findDepth(root);
        // return solve(root, 1);
        if(root == null) return 0;
        Queue<TreeNode>q = new LinkedList<>();
        q.add(root);
        int ans = 0;
        while(!q.isEmpty()) {
            int sz = q.size();
            int temp = 0;
            while(sz-- > 0) {
                TreeNode cur = q.poll();
                temp += cur.val;
                if(cur.left != null) q.add(cur.left);
                if(cur.right != null) q.add(cur.right);
            }
            ans = temp;
        }
        return ans;
    }
}