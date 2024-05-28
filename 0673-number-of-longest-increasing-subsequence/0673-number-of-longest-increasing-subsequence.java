class Solution {
    public int findNumberOfLIS(int[] nums) {
        int n = nums.length, ans = 0, maxLen = 1;
        int[] count = new int[n];
        int[] dp = new int[n];
        Arrays.fill(count, 1);
        Arrays.fill(dp, 1);
        for(int i=1; i<n; i++) {
            for(int j=i-1; j>=0; j--) {
                if(nums[i] > nums[j]) {
                    if(dp[j] + 1 > dp[i]) {
                        dp[i] = dp[j] + 1;
                        count[i] = count[j];
                    }
                    else if(dp[j] + 1 == dp[i]) {
                        count[i] += count[j];
                    }
                }
            }
            maxLen = Math.max(maxLen, dp[i]);
        }
        for(int i=0; i<n; i++) {
            if(maxLen == dp[i]) ans += count[i];
        }
        return ans;
    }
}