class Solution {
    int solve(String text1, String text2, int i, int j, int[][]dp) {
        if(i == text1.length() || j == text2.length()) return 0;
        if(dp[i][j] != -1) return dp[i][j];
        if(text1.charAt(i) == text2.charAt(j)) {
            return dp[i][j] = 1 + solve(text1, text2, i+1, j+1, dp);
        }
        else {
            return dp[i][j] = Math.max(solve(text1, text2, i+1, j, dp), solve(text1, text2, i, j+1, dp));
        }
    }
    public int longestCommonSubsequence(String text1, String text2) {
        int n = text1.length(), m = text2.length();
        int[][] dp = new int[n][m];
        for(int[] row:dp) {
            Arrays.fill(row, -1);
        }
        return solve(text1, text2, 0, 0, dp);
    }
}