class Solution {
public:
    int solve(string &s1, string &s2, int i, int j, vector<vector<int>>&dp) {
        if(i == s1.size()) return s2.size() - j;
        if(j == s2.size()) return s1.size() - i;
        if(dp[i][j] != -1) return dp[i][j];
        if(s1[i] == s2[j]) return dp[i][j] = solve(s1, s2, i+1, j+1, dp);
        else return dp[i][j] = 1 + min(solve(s1, s2, i+1, j, dp), solve(s1, s2, i, j+1, dp));
    }
    int minDistance(string word1, string word2) {
        int n = word1.size(), m = word2.size();
        vector<vector<int>>dp(n, vector<int>(m, -1));
        return solve(word1, word2, 0, 0, dp);
    }
};