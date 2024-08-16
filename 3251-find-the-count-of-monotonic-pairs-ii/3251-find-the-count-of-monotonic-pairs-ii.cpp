class Solution {
public:
    int countOfPairs(vector<int>& nums) {
        // A[i-1] - arr[i-1] >= A[i] - arr[i]
        // arr[i-1] - A[i-1] <= arr[i] - A[i] 
        // A[i] - A[i-1] + arr[i-1] <= arr[i]
        // d + arr[i-1] <= arr[i], where d = 0...(arr[i] - arr[i-1])
        int n = nums.size(), mod = 1e9+7, ans = 0;
        vector<vector<int>>dp(n, vector<int>(1001, 0));
        for(int i=0; i<=nums[0]; i++) {
            dp[0][i] = 1;
        }
        for(int i=1; i<n; i++) {
            int ways = 0, k = 0;
            for(int j=0; j<=nums[i]; j++) {
                if(k <= min(j, j - (nums[i] - nums[i-1]))) {
                    ways = (ways + dp[i-1][k])%mod;
                    k++;
                }
                dp[i][j] = ways;
            }
        }
        for(int i=0; i<=1000; i++) {
            ans = (ans + dp[n-1][i])%mod;
        }
        return ans;
    }
};