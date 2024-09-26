class Solution {
    public int maximalSquare(char[][] mat) {
        int n = mat.length, m = mat[0].length;
        int[][] dp = new int[n+1][m+1];
        int len = 0;
        for(int i=1; i<=n; i++) {
            for(int j=1; j<=m; j++) {
                if(mat[i-1][j-1] == '1') {
                    int mn = Math.min(dp[i-1][j-1], Math.min(dp[i-1][j], dp[i][j-1])) + 1;
                    dp[i][j] = mn;
                    len = Math.max(len, mn);
                }
            }
        }
        return len * len;
    }
}