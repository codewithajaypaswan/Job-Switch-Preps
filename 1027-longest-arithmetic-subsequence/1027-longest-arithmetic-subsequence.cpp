class Solution {
public:
    int longestArithSeqLength(vector<int>& nums) {
        int n = nums.size(), ans = 0;
        vector<vector<int>>dp(n+1, vector<int>(2001, 0));
        // dp[n][diff] : n = len of array nums with 0 based indexing
        //             : diff = diff is the length of largest array with the difference equals to diff
        //.            : dp[n][diff] tell us about the length of the largest arrays of diffence equals to diff
        for(int i=1; i<n; i++) {
            for(int j=0; j<i; j++) {
                int diff = nums[i] - nums[j] + 1000;
                if(dp[j][diff] + 1 > dp[i][diff]) {
                    dp[i][diff] = max(2, dp[j][diff] + 1);
                    ans = max(ans, dp[i][diff]);
                }
            }
        }
        return ans;
    }
};