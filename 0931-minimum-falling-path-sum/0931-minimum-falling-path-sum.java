class Solution {
    public int minFallingPathSum(int[][] mat) {
        int n = mat.length, m = mat[0].length;
        int[] dp = new int[m];
        for(int i=0; i<m; i++) dp[i] = mat[0][i];
        for(int i=1; i<n; i++) {
            int[] temp = new int[m];
            for(int j=0; j<m; j++) {
                if(j == 0 && j+1 < m) temp[j] = mat[i][j] + Math.min(dp[j], dp[j+1]);
                if(j == m-1 && j-1 >= 0) temp[j] = mat[i][j] + Math.min(dp[j], dp[j-1]);
                else if(j-1 >= 0 && j+1 < m) temp[j] = mat[i][j] + Math.min(Math.min(dp[j], dp[j-1]), dp[j+1]);
            }
            dp = temp;
        }
        int ans = Integer.MAX_VALUE;
        for(int i=0; i<m; i++) ans = Math.min(ans, dp[i]);
        return ans;
    }
    public int solve(int[][] mat, int[][] dp, int row, int col) {
        if(row == mat.length-1 && col >= 0 && col < mat[0].length) return mat[row][col];
        if(col < 0 || col >= mat[0].length) return Integer.MAX_VALUE;
        if(dp[row][col] != Integer.MAX_VALUE) return dp[row][col];
        return dp[row][col] = mat[row][col] + Math.min(Math.min(solve(mat, dp, row+1, col), solve(mat, dp, row+1, col+1)), solve(mat, dp, row+1, col-1));
    }
}