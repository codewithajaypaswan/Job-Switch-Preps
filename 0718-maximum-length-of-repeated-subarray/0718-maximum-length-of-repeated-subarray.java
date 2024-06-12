class Solution {
    int ans = 0;
    public int findLength(int[] nums1, int[] nums2) {
        int n = nums1.length, m = nums2.length;
        int[][] dp = new int[n][m];
        for(int i=0; i<n; i++) {
            Arrays.fill(dp[i], -1);
        }
        solve(nums1, nums2, 0, 0, dp);
        return ans;
    }
    int solve(int[] nums1, int[] nums2, int i, int j, int[][] dp) {
        if(i == nums1.length || j == nums2.length) return 0;
        if(dp[i][j] != -1) return dp[i][j];
        solve(nums1, nums2, i+1, j, dp);
        solve(nums1, nums2, i, j+1, dp);
        if(nums1[i] == nums2[j]) {
            dp[i][j] = 1 + solve(nums1, nums2, i+1, j+1, dp);
            ans = Math.max(dp[i][j], ans);
        }
        else {
            dp[i][j] = 0;
        }
        return dp[i][j];
    }
}