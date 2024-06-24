class Solution {
    
    public long maximumTotalCost(int[] nums) {
        int n = nums.length;
        long[][] dp = new long[n][2];
        for(int i=0; i<n; i++) {
            Arrays.fill(dp[i], Long.MAX_VALUE);
        }
        return solve(nums, 0, dp, 0);
    }
    long solve(int[]nums, int cur, long[][] dp, int flag) {
        if(cur >= nums.length) return 0;
        if(dp[cur][flag] != Long.MAX_VALUE) return dp[cur][flag];
        long noFlip = nums[cur] + solve(nums, cur+1, dp, 1);
        long flip = 0;
        if(flag == 1) {
            flip += -nums[cur] + solve(nums, cur+1, dp, 0);
        }
        else {
            flip += nums[cur] + solve(nums, cur+1, dp, 1);
        }
        return dp[cur][flag] = Math.max(flip, noFlip);
    }
}