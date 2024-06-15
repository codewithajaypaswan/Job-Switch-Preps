class Solution {
public:
    int solve(vector<int>&nums, int low, int high) {
        int n = nums.size();
        if(n <= 1) return nums[0];
        if(n <= 2) return max(nums[0], nums[1]);
        vector<int>dp(n, 0);
        dp[low] = nums[low];
        dp[low+1] = max(nums[low+1], nums[low]);
        for(int i=low+2; i<=high; i++) {
            dp[i] = max(dp[i-2] + nums[i], dp[i-1]);
        }
        return dp[high];
    }
    int rob(vector<int>& nums) {
        int n = nums.size();
        return max(solve(nums, 0, n-2), solve(nums, 1, n-1));
    }
};