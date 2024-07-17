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
    List<TreeNode> ans = new ArrayList<>();
    Set<Integer>st = new HashSet<>();
    public List<TreeNode> delNodes(TreeNode root, int[] to_delete) {
        for(int x:to_delete) {
            st.add(x);
        }
        if(!st.contains(root.val)) ans.add(root);
        solve(root);
        return ans;
    }
    TreeNode solve(TreeNode root) {
        if(root == null) return null;
        root.left = solve(root.left);
        root.right = solve(root.right);
        if(st.contains(root.val)) {
            if(root.left != null && !st.contains(root.left.val)) {
                ans.add(root.left);
            }
            if(root.right != null && !st.contains(root.right.val)) {
                ans.add(root.right);
            }
            return null;
        }
        return root;
    }
}