class Solution {
    int[][][] dp;
    public boolean stoneGame(int[] piles) {
        int n = piles.length;
        int[][][] dp = new int[2][n][n];
        for(int[][] arr:dp) {
            for(int[] sub:arr) Arrays.fill(sub, -1);
        }
        return solve(piles, dp, 0, n-1, 1) > 0;
    }
    int solve(int[] piles, int[][][] dp, int i, int j, int person) {
        if(i > j) return 0;
        if(dp[person][i][j] != -1) return dp[person][i][j];
        if(person == 1) {
            // Alice will maximize the score
            return dp[person][i][j] = Math.max(piles[i] - solve(piles, dp, i+1, j, 0), piles[j] - solve(piles, dp, i, j-1, 0));
        }
        else {
            // Bob will minimize the score
            return dp[person][i][j] = Math.min(-piles[i] - solve(piles, dp, i+1, j, 1), -piles[j] - solve(piles, dp, i, j-1, 1));
        }
    }
}