class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<int>dp(n, 1);
        for(int i=1; i<n; i++) {
            for(int j=i; j>=0; j--) {
                if(nums[i] > nums[j] && dp[j] + 1 > dp[i]) {
                    dp[i] = dp[j] + 1;
                }
            }
        }
        int mx = *max_element(dp.begin(), dp.end());
        return mx;
    }
};