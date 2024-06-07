class Solution {
    public int minFallingPathSum(int[][] mat) {
        int n = mat.length, m = mat[0].length;
        int[][] dp = new int[n][m];
        for(int i=0; i<n; i++) Arrays.fill(dp[i], Integer.MAX_VALUE);
        int ans = Integer.MAX_VALUE;
        for(int c=0; c<m; c++) {
            ans = Math.min(ans, solve(mat, dp, 0, c));
        }
        return ans;
    }
    public int solve(int[][] mat, int[][] dp, int row, int col) {
        if(row == mat.length-1 && col >= 0 && col < mat[0].length) return mat[row][col];
        if(col < 0 || col >= mat[0].length) return Integer.MAX_VALUE;
        if(dp[row][col] != Integer.MAX_VALUE) return dp[row][col];
        return dp[row][col] = mat[row][col] + Math.min(Math.min(solve(mat, dp, row+1, col), solve(mat, dp, row+1, col+1)), solve(mat, dp, row+1, col-1));
    }
}