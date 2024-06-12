class Solution {
    int total = 0;
    public int findTargetSumWays(int[] nums, int target) {
        int n = nums.length;
        for(int x:nums) {
            total += Math.abs(x);
        }
        int[][] dp = new int[n+1][2*total + 1];
        for(int i=0; i<=n; i++) {
            Arrays.fill(dp[i], -1);
        }
        return solve(nums, target, 0, 0, dp);
    }
    private int solve(int[] nums, int target, int cur, int sum, int[][] dp) {
        if(cur >= nums.length) {
            return target == sum ? 1 : 0;
        }
        if(dp[cur][total + sum] != -1) return dp[cur][total + sum];
        int ways1 = solve(nums, target, cur+1, sum + nums[cur], dp);
        int ways2 = solve(nums, target, cur+1, sum - nums[cur], dp);
        return dp[cur][total + sum] = ways1 + ways2;
    }
}