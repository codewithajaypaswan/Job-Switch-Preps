class Solution {
public:
    int minTaps(int n, vector<int>& ranges) {
        vector<int>dp(n+1, 1e9);
        dp[0] = 0;
        for(int i=0; i<=n; i++) {
            int start = max(0, i - ranges[i]);
            int end = min(n, i + ranges[i]);
            for(int i=start; i<=end; i++) {
                dp[i] = min(dp[start] + 1, dp[i]);
            }
        }
        return dp[n] == 1e9 ? -1 : dp[n];
    }
};
// 0, 1, 2, 3, 4, 5

//     n+1
// ranges = {3, 4, 1, 1, 0, 0}
// 0 -> {-3, 3}
// 1 -> {-3, 5}
// 2 -> {1, 3}
// 3 -> {2, 4}
// 4 -> {4, 4}
// 5 -> {5, 5}

// 3 -> {0, 3}
// 4 -> {0, 5}
// dp - {0, 1, 1, 1, 1, 1}
