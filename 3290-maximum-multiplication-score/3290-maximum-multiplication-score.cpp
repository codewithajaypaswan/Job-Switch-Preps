class Solution {
public:
    long long mn = -1e15;
    long long solve(vector<int>&a, vector<int>&b, int i, int j, vector<vector<long long>>&dp) {
        if(a.size() == i) return 0;
        if(b.size() == j) return mn;
        if(dp[i][j] != mn) return dp[i][j];
        long long take = 1LL * a[i] * b[j] + solve(a, b, i+1, j+1, dp);
        long long noTake = solve(a, b, i, j+1, dp);
        return dp[i][j] = max(take, noTake);
    }
    long long maxScore(vector<int>& a, vector<int>& b) {
        vector<vector<long long>>dp(4, vector<long long>(b.size(), mn));
        return solve(a, b, 0, 0, dp);
    }
};