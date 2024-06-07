class Solution {
public:
    int countSubstrings(string s) {
        int n = s.size();
        vector<vector<int>>dp(n, vector<int>(n, 0));
        int ans = 0;
        for(int i=0; i<n; i++) {
            dp[i][i] = 1;
            ans++;
        }
        for(int i=0; i<n-1; i++) {
            if(s[i] == s[i+1]) {
                dp[i][i+1] = 1;
                ans++;
            }
        }
        for(int len = 3; len <= n; len++) {
            for(int i=0, j = len-1; j<n; i++, j++) {
                dp[i][j] = dp[i+1][j-1] && (s[i] == s[j]);
                ans += dp[i][j];
            }
        }
        return ans;
    }
};