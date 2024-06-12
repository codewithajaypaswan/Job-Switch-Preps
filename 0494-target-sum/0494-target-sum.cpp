class Solution {
public:
    int total = 0;
    int findTargetSumWays(vector<int>& nums, int target) {
        int n = nums.size();
        for(int x:nums) {
            total += abs(x);
        }
        cout<<2*total + 1<<endl;
        vector<vector<int>>dp(n+1, vector<int>(2*total + 1, -1));
        return solve(nums, target, 0, dp, 0);
    }
    int solve(vector<int>& nums, int target, int cur, vector<vector<int>>&dp, int sum) {
        if(cur == nums.size()) {
            return target == sum;
        }
        if(dp[cur][sum + total] != -1) return dp[cur][sum + total];
        int ways1 = solve(nums, target, cur + 1, dp, sum + nums[cur]);
        int ways2 = solve(nums, target, cur + 1, dp, sum - nums[cur]);
        return dp[cur][sum + total] = ways1 + ways2;
    }
};