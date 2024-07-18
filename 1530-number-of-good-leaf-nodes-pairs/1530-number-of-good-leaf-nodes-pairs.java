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
    int ans = 0;
    List<Integer> dfs(TreeNode root, int dist) {
        if(root == null) return new ArrayList<>();
        if(root.left == null && root.right == null) return new ArrayList<>(Arrays.asList(1));
        List<Integer>leftLeaf = dfs(root.left, dist);
        List<Integer>rightLeaf = dfs(root.right, dist);
        for(int x:leftLeaf) {
            for(int y:rightLeaf) {
                if(x+y <= dist) ans++;
            }
        }
        List<Integer>overAllLeaf = new ArrayList<>();
        for(int x:leftLeaf) overAllLeaf.add(x + 1);
        for(int x:rightLeaf) overAllLeaf.add(x+1);
        return overAllLeaf;
    }
    public int countPairs(TreeNode root, int distance) {
        dfs(root, distance);
        return ans;
    }
}