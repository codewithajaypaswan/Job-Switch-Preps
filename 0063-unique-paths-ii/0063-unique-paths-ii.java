class Solution {
    public int uniquePathsWithObstacles(int[][] mat) {
        int n = mat.length, m = mat[0].length;
        int[][] dp = new int[n][m];
        for(int i=0; i<n; i++) {
            if(mat[i][0] == 1) break;
            dp[i][0] = 1;
        }
        for(int j=0; j<m; j++) {
            if(mat[0][j] == 1) break;
            dp[0][j] = 1;
        }
        
        for(int i=1; i<n; i++) {
            for(int j=1; j<m; j++) {
                if(mat[i][j] == 1) dp[i][j] = 0;
                else dp[i][j] = dp[i-1][j] + dp[i][j-1];
            }
        }
        return dp[n-1][m-1];
    }
}