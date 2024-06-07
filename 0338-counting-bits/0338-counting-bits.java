class Solution {
    public int count(int x) {
        int ans = 0;
        while(x > 0) {
            ans++;
            x = x&(x-1);
        }
        return ans;
    }
    public int[] countBits(int n) {
        int[] dp = new int[n+1];
        for(int i=1; i<=n; i++) {
            dp[i] = dp[i&(i-1)] + 1;
        }
        return dp;
    }
}