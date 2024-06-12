class Solution {
public:
    int deleteAndEarn(vector<int>& nums) {
        int mx = *max_element(nums.begin(), nums.end());
        vector<int>dp(mx+1, -1), freq(mx+1, 0);
        for(int x:nums) {
            freq[x] += x;
        }
        return solve(nums, dp, freq, 0);
    }
    int solve(vector<int>&nums, vector<int>&dp, vector<int>&freq, int cur) {
        if(cur >= freq.size()) return 0;
        if(dp[cur] != -1) return dp[cur];
        return dp[cur] = max(freq[cur] + solve(nums, dp, freq, cur + 2), solve(nums, dp, freq, cur+1));
    }
};