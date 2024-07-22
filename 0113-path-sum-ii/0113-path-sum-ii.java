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
    List<List<Integer>>ans = new ArrayList<>();
    void solve(TreeNode root, int target, List<Integer>temp) {
        if(root == null) return;
        temp.add(root.val);
        if(root.left == null && root.right == null && root.val == target) {
            ans.add(new ArrayList<>(temp));
        }
        solve(root.left, target - root.val, temp);
        solve(root.right, target - root.val, temp);
        temp.remove(temp.size() - 1);
    }
    public List<List<Integer>> pathSum(TreeNode root, int targetSum) {
        List<Integer>temp = new ArrayList<>();
        solve(root, targetSum, temp);
        return ans;
    }
}