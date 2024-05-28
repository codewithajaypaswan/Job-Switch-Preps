class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        int n = nums.size(), maxLen = 1;
        vector<int>count(n, 1), dp(n, 1);
        for(int i=1; i<n; i++) {
            for(int j=i-1; j>=0; j--) {
                if(nums[i] > nums[j]) {
                    if(dp[i] < dp[j] + 1) {
                        dp[i] = dp[j] + 1;
                        count[i] = count[j];
                    }
                    else if(dp[i] == dp[j] + 1) {
                        count[i] += count[j];
                    }
                    maxLen = max(maxLen, dp[i]);
                }
            }
        }
        int ans = 0;
        for(int i=0; i<n; i++) {
            if(maxLen == dp[i]) ans += count[i];
        }
        return ans;
    }
};