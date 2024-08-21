class Solution {
public:
    int strangePrinter(string s) {
        int n = s.size();
        vector<vector<int>>dp(n, vector<int>(n, -1));
        return solve(s, 0, n-1, dp);
    }
    int solve(string &s, int l, int r, vector<vector<int>>&dp) {
        if(l == r) return 1;
        if(l > r) return 0;
        if(dp[l][r] != -1) return dp[l][r];
        int i = l+1;
        while(i < s.size() && s[i] == s[l]) i++;
        if(i == r+1) return 1;
        int case1 = 1 + solve(s, i, r, dp);
        int case2 = INT_MAX;
        for(int j = i+1; j<=r; j++) {
            if(s[l] == s[j]) {
                int ans = solve(s, i, j-1, dp) + solve(s, j, r, dp);
                case2 = min(ans, case2);
            }
        }
        return dp[l][r] = min(case1, case2);
    }
};