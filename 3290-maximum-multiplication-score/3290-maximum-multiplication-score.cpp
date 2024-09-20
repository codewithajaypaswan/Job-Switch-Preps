class Solution {
public:
    long long mn = -1e11;
    long long maxScore(vector<int>& a, vector<int>& b) {
        int n = b.size();
        vector<vector<long long>>dp(5, vector<long long>(n+1, mn));
        for(int i=0; i<=n; i++) {
            dp[0][i] = 0;
        }
        for(int i=1; i<=4; i++) {
            for(int j=1; j<=n; j++) {
                long long take = dp[i-1][j-1] + (long long)a[i-1]*(long long)b[j-1];
                long long noTake = dp[i][j-1];
                dp[i][j] = max(take, noTake);
            }
        }
        return dp[4][n];
    }
};

/*


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

*/