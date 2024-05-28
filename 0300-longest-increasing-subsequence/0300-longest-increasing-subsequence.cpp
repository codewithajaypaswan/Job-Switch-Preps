class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        int ans = n == 0 ? 0 : 1;
        vector<int>dp(n, 1);
        for(int i=1; i<n; i++) {
            for(int j=i-1; j>=0; j--) {
                if(nums[i] > nums[j] && dp[j] + 1 > dp[i]) {
                    dp[i] = dp[j] + 1;
                    ans = max(ans, dp[i]);
                }
            }
        }
        return ans;
    }
};