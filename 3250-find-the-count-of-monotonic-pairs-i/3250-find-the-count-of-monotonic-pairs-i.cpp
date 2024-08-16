class Solution {
public:
    int mod = 1e9+7;
    vector<vector<vector<int>>>dp;
    int solve(vector<int>&nums, int cur, int prev1, int prev2) {
        if(cur == nums.size()) return 1;
        if(dp[cur][prev1][prev2] != -1) return dp[cur][prev1][prev2];
        int ans = 0;
        for(int i=prev1; i<=nums[cur]; i++) {
            int j = nums[cur] - i;
            if(j <= prev2) {
                ans = (ans%mod + solve(nums, cur+1, i, j))%mod;
            }
        }
        return dp[cur][prev1][prev2] = ans;
    }
    int countOfPairs(vector<int>& nums) {
        int n = nums.size();
        dp = vector<vector<vector<int>>>(n, vector<vector<int>>(51, vector<int>(51, -1)));
        return solve(nums, 0, 0, 50);
    }
};