class Solution {
    int solve(String s1, String s2, int i, int j, int[][] dp) {
        if(i == s1.length()) return s2.length() - j;
        if(j == s2.length()) return s1.length() - i;
        if(dp[i][j] != -1) return dp[i][j];
        if(s1.charAt(i) == s2.charAt(j)) return dp[i][j] = solve(s1, s2, i+1, j+1, dp);
        else return dp[i][j] = 1 + Math.min(solve(s1, s2, i+1, j, dp), solve(s1, s2, i, j+1, dp));
    }
    public int minDistance(String word1, String word2) {
        int n = word1.length(), m = word2.length();
        int[][] dp = new int[n+1][m+1];
        for(int i=0; i<=n; i++) {
            dp[i][0] = i;
        }
        for(int j=0; j<=m; j++) {
            dp[0][j] = j;
        }
        for(int i=1; i<=n; i++) {
            for(int j=1; j<=m; j++) {
                if(word1.charAt(i-1) == word2.charAt(j-1)) {
                    dp[i][j] = dp[i-1][j-1];
                }
                else {
                    dp[i][j] = 1 + Math.min(dp[i-1][j], dp[i][j-1]);
                }
            }
        }
        return dp[n][m];
    }
}