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
    public List<Integer> preorderTraversal(TreeNode root) {
        List<Integer>ans = new ArrayList<>();
        Stack<TreeNode>stack = new Stack<TreeNode>();
        TreeNode cur = new TreeNode();
        cur = root;
        while(cur != null || !stack.isEmpty()) {
            if(cur != null) {
                ans.add(cur.val);
                stack.push(cur);
                cur = cur.left;
            }
            else {
                cur = stack.pop();
                cur = cur.right;
            }
        }
        return ans;
    }
}