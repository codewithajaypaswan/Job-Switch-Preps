class Solution {
    public int findCenter(int[][] edges) {
        int n = edges.length;
        int[] inorder = new int[n+2];
        for(int i=0; i<n; i++) {
            inorder[edges[i][0]]++;
            inorder[edges[i][1]]++;
        }
        for(int i=1; i<=n; i++) {
            if(inorder[i] == n) return i;
        }
        return n+1;
    }
}