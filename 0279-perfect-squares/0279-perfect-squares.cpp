class Solution {
public:
    int solve(vector<int>&dp, int cur) {
        if(cur == 0) return 0;
        if(cur < 0) return 1e9;
        int ans = 1e9;
        if(dp[cur] != -1) return dp[cur];
        for(int i=1; i*i <= cur; i++) {
            ans = min(1 + solve(dp, cur - i*i), ans);
        }
        return dp[cur] = ans;
    }
    int numSquares(int n) {
        vector<int>dp(n+1, -1);
        return solve(dp, n);
    }
};