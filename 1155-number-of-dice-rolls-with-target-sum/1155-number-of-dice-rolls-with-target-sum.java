class Solution {
    int mod = 1_000_000_007;
    public int numRollsToTarget(int n, int k, int target) {
        // int[][]dp = new int[n+1][target+1];
        // for(int i=0; i<=n; i++) {
        //     Arrays.fill(dp[i], -1);
        // }
        // return solve(n, k, target, dp);
        int[] dp = new int[target + 1];
        dp[0] = 1;
        for(int x=1; x<=n; x++) {
            for(int i=target; i>=0; i--) {
                int ways = 0;
                for(int j=i-1; j>=Math.max(0, i - k); j--) {
                    ways = (ways + dp[j])%mod;
                }
                dp[i] = ways;
            }
        }
        return dp[target];
    }
    private int solve(int n, int k, int target, int[][]dp) {
        if(n == 0 && target == 0) return 1;
        if(n < 0 || target < 0) return 0;
        if(dp[n][target] != -1) return dp[n][target];
        int ans = 0;
        for(int i=1; i<=k; i++) {
            ans = ((ans%mod + solve(n-1, k, target-i, dp)%mod))%mod;
        }
        return dp[n][target] = ans;
    }
}