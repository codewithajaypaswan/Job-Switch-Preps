class Solution {
    public int deleteAndEarn(int[] nums) {
        int n = nums.length;
        if(n == 1) return nums[0];
        int mx = Integer.MIN_VALUE;
        for(int x:nums) {
            if(mx < x) mx = x;
        }
        int[] dp = new int[mx+1];
        int[] freq = new int[mx+1];
        // Arrays.fill(dp, -1);
        for(int x:nums) {
            freq[x] += x;
        }
        dp[0] = freq[0];
        dp[1] = freq[1];
        for(int i=2; i<=mx; i++) {
            dp[i] = Math.max(freq[i] + dp[i-2], dp[i-1]);
        }
        return dp[mx];
        // return solve(dp, freq, 0);
    }
    private int solve(int[] dp, int[] freq, int cur) {
        if(cur >= freq.length) return 0;
        if(dp[cur] != -1) return dp[cur];
        return dp[cur] = Math.max(freq[cur] + solve(dp, freq, cur+2), solve(dp, freq, cur+1));
    }
}