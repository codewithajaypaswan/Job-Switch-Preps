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
        int[][] dp = new int[n][m];
        for(int[]arr : dp) {
            Arrays.fill(arr, -1);
        }
        return solve(word1, word2, 0, 0, dp);
    }
}