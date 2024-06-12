class Solution {
public:
    int deleteAndEarn(vector<int>& nums) {
        int n = nums.size();
        if(n == 1) return nums[0];
        int mx = *max_element(nums.begin(), nums.end());
        vector<int>dp(mx+1, 0), freq(mx+1, 0);
        for(int x:nums) {
            freq[x] += x;
        }
        dp[0] = freq[0];
        dp[1] = max(freq[0], freq[1]);
        for(int i=2; i<=mx; i++) {
            dp[i] = max(dp[i-2] + freq[i], dp[i-1]);
        }
        return dp[mx];
    }
    int solve(vector<int>&nums, vector<int>&dp, vector<int>&freq, int cur) {
        if(cur >= freq.size()) return 0;
        if(dp[cur] != -1) return dp[cur];
        return dp[cur] = max(freq[cur] + solve(nums, dp, freq, cur + 2), solve(nums, dp, freq, cur+1));
    }
};