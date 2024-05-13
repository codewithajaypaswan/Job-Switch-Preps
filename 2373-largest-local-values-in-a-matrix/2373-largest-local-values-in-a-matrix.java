class Solution {
    public int[][] largestLocal(int[][] grid) {
        int n = grid.length; 
        int[][] ans = new int[n-2][n-2];
        for(int i=0; i<n-2; i++) {
            for(int j=0; j<n-2; j++) {
                ans[i][j] = find_max(grid, i, j);
            }
        }
        return ans;
    }
    
    int find_max(int[][] grid, int x, int y) {
        int ans = Integer.MIN_VALUE;
        for(int i=x; i <= x+2; i++) {
            for(int j=y; j <= y+2; j++) {
                ans = Math.max(ans, grid[i][j]);
            }
        }
        return ans;
    }
}