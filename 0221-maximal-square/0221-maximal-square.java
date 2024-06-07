class Solution {
    public int maximalSquare(char[][] mat) {
        int n = mat.length, m = mat[0].length, len = 0;
        int[][] dp = new int[n+1][m+1];
        for(int i=1; i<=n; i++) {
            for(int j=1; j<=m; j++) {
                if(mat[i-1][j-1] == '1') {
                    dp[i][j] = Math.min(Math.min(dp[i-1][j], dp[i][j-1]), dp[i-1][j-1]) + 1;
                    len = Math.max(len, dp[i][j]);
                }
            }
        }
        return len*len;
    }
}