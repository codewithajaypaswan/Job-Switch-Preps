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
    int maxDepth = -1;
    void dfs(TreeNode root, List<Integer>list, int depth) {
        if(root == null) return;
        if(depth > maxDepth) {
            list.add(root.val);
            maxDepth = depth;
        }
        dfs(root.right, list, depth + 1);
        dfs(root.left, list, depth + 1);
    }
    public List<Integer> rightSideView(TreeNode root) {
        List<Integer>list = new ArrayList<>();
        dfs(root, list, 0);
        return list;
    }
}