class Solution {
public:
    int solve(int x, int y, int m, int n, vector<vector<int>>&dp) {
        if(x == m && y == n) return 1;
        if(x > m || y > n) return 0;
        if(dp[x][y] != -1) return dp[x][y];
        return dp[x][y] = solve(x+1, y, m, n, dp) + solve(x, y+1, m, n, dp);
    }
    int uniquePaths(int m, int n) {
        vector<vector<int>>dp(m+1, vector<int>(n+1, 0));
        for(int i=0; i<m; i++) dp[i][0] = 1;
        for(int j=0; j<n; j++) dp[0][j] = 1;
        for(int i=1; i<m; i++) {
            for(int j=1; j<n; j++) {
                dp[i][j] = dp[i-1][j] + dp[i][j-1];
            }
        }
        return dp[m-1][n-1];
    }
};