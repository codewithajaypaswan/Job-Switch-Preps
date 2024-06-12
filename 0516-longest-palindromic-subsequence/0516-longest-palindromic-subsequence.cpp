class Solution {
public:
    int longestPalindromeSubseq(string s) {
        int n = s.size();
        vector<vector<int>>dp(n+1, vector<int>(n+1, 0));
        // return solve(s, 0, n-1, dp);
        for(int len=1; len<=n; len++) {
            for(int i=0; i<=n-len; i++) {
                int j = i+len-1;
                if(i == j) {
                    dp[i][j] = 1;
                    continue;
                }
                dp[i][j] = max(dp[i+1][j], dp[i][j-1]);
                if(s[i] == s[j]) {
                    dp[i][j] = max(dp[i][j], 2 + dp[i+1][j-1]);
                }
            }
        }
        return dp[0][n-1];
    }
    int solve(string &s, int i, int j, vector<vector<int>>&dp) {
        if(i > j) return 0;
        if(i == j) return 1;
        if(dp[i][j] != -1) return dp[i][j];
        if(s[i] == s[j]) {
            return dp[i][j] = 2 + solve(s, i+1, j-1, dp);
        }
        else {
            return dp[i][j] = max(solve(s, i+1, j, dp), solve(s, i, j-1, dp));
        }
    }
};