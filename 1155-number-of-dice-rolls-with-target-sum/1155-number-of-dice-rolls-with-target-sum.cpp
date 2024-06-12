class Solution {
public:
    int mod = 1e9+7;
    int numRollsToTarget(int n, int face, int target) {
        vector<int>dp(target + 1);
        dp[0] = 1;
        for(int x=1; x<=n; x++) {
            for(int i=target; i>=0; i--) {
                int ways = 0;
                for(int j = i-1; j>=max(0, i - face); j--) {
                    ways = (ways + dp[j])%mod;
                }
                dp[i] = ways;
            }
        }
        return dp[target];
    }
    int solve(int n, int k, int target, vector<vector<int>>&dp) {
        if(n == 0 && target == 0) return 1;
        if(n < 0 || target < 0) return 0;
        if(dp[n][target] != -1) return dp[n][target];
        int ans = 0;
        for(int i=1; i<=k; i++) {
            ans = (0LL + ans%mod + solve(n-1, k, target - i, dp))%mod;
        }
        return dp[n][target] = ans;
    }
};