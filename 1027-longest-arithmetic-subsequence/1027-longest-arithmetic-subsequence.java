class Solution {
    public int longestArithSeqLength(int[] nums) {
        // dp[n][diff] : n = len of array nums with 0 based indexing
        //             : diff = diff is the length of largest array with the difference equals to diff
        //.            : dp[n][diff] tell us about the length of the largest arrays of diffence equals to diff
        int n = nums.length, ans = 0;
        int[][] dp = new int[n][2001];
        for(int i=1; i<n; i++) {
            for(int j=0; j<i; j++) {
                int diff = nums[i] - nums[j] + 1000;
                if(dp[j][diff] + 1 > dp[i][diff]) {
                    dp[i][diff] = Math.max(2, 1 + dp[j][diff]);
                    ans = Math.max(ans, dp[i][diff]);
                }
            }
        }
        return ans;
    }
}