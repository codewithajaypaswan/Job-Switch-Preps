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
    public List<Integer> postorderTraversal(TreeNode root) {
        List<Integer>list = new ArrayList<>();
        Stack<TreeNode>stack = new Stack<TreeNode>();
        TreeNode last = null;
        while(root != null || !stack.isEmpty()) {
            if(root != null) {
                stack.push(root);
                root = root.left;
            }
            else {
                TreeNode node = stack.peek();
                if(node.right != null && node.right != last) {
                    root = node.right;
                }
                else {
                    list.add(node.val);
                    last = node;
                    stack.pop();
                }
            }
        }
        return list;
    }
}