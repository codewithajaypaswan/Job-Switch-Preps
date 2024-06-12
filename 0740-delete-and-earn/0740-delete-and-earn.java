class Solution {
    public int deleteAndEarn(int[] nums) {
        int n = nums.length;
        int mx = Integer.MIN_VALUE;
        for(int x:nums) {
            if(mx < x) mx = x;
        }
        int[] dp = new int[mx+1];
        int[] freq = new int[mx+1];
        Arrays.fill(dp, -1);
        for(int x:nums) {
            freq[x] += x;
        }
        return solve(dp, freq, 0);
    }
    private int solve(int[] dp, int[] freq, int cur) {
        if(cur >= freq.length) return 0;
        if(dp[cur] != -1) return dp[cur];
        return dp[cur] = Math.max(freq[cur] + solve(dp, freq, cur+2), solve(dp, freq, cur+1));
    }
}