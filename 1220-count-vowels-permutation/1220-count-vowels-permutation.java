class Solution {
    public int countVowelPermutation(int n) {
        long[][] dp = new long[n][5];
        long mod = 1_000_000_007;
        for(int i=0; i<5; i++) {
            dp[n-1][i] = 1;
        }
        for(int i=n-2; i>=0; i--) {
            dp[i][0] = (dp[i+1][1])%mod;
            dp[i][1] = (dp[i+1][0]%mod + dp[i+1][2])%mod;
            dp[i][2] = (dp[i+1][0]%mod + dp[i+1][1]%mod + dp[i+1][3]%mod + dp[i+1][4]%mod)%mod;
            dp[i][3] = (dp[i+1][2]%mod + dp[i+1][4]%mod);
            dp[i][4] = (dp[i+1][0])%mod;
        }
        long ans = 0;
        for(int i=0; i<5; i++) {
            ans = (ans + dp[0][i])%mod;
        }
        return (int) ans;
    }
}