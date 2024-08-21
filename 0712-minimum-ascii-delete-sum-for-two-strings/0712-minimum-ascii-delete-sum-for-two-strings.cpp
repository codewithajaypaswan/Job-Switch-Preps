class Solution {
public:
    int minimumDeleteSum(string s1, string s2) {
        int n = s1.size(), m = s2.size();
        vector<vector<int>>dp(n, vector<int>(m, -1));
        return solve(s1, s2, 0, 0, dp);
    }
    int solve(string &s1, string &s2, int i, int j, vector<vector<int>>&dp) {
        if(i == s1.size()) {
            int ans = 0;
            while(j < s2.size()) ans += s2[j++];
            return ans;
        }
        if(j == s2.size()) {
            int ans = 0;
            while(i < s1.size()) ans += s1[i++];
            return ans;
        }
        if(dp[i][j] != -1) return dp[i][j];
        if(s1[i] == s2[j]) {
            return dp[i][j] = solve(s1, s2, i+1, j+1, dp);
        }
        else {
            return dp[i][j] = min(s1[i] + solve(s1, s2, i+1, j, dp), s2[j] + solve(s1, s2, i, j+1, dp));
        }
    }
};