class Solution {
public:
    int ans = 0;
    int solve(vector<int>&nums1, vector<int>&nums2, int i, int j, vector<vector<int>>&dp) {
        if(i == nums1.size() || j == nums2.size()) return 0;
        if(dp[i][j] != -1) return dp[i][j];
        solve(nums1, nums2, i+1, j, dp);
        solve(nums1, nums2, i, j+1, dp);
        if(nums1[i] == nums2[j]) {
            dp[i][j] = 1 + solve(nums1, nums2, i+1, j+1, dp);
            ans = max(ans, dp[i][j]);
        }
        else {
            dp[i][j] = 0;
        }
        return dp[i][j];
    }
    int findLength(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size(), m = nums2.size();
        vector<vector<int>>dp(n, vector<int>(m, -1));
        solve(nums1, nums2, 0, 0, dp);
        return ans;
    }
};