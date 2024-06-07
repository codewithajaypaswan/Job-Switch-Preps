class Solution {
    public int countSubstrings(String s) {
        int n = s.length();
        int[][] dp = new int[n][n];
        int ans = 0;
        for(int i=0; i<n; i++) {
            dp[i][i] = 1;
            ans++;
        }
        for(int i=0; i<n-1; i++) {
            if(s.charAt(i) == s.charAt(i+1)) {
                dp[i][i+1] = 1;
                ans++;
            }
        }
        for(int len=3; len<=n; len++) {
            for(int i=0, j=len-1; j<n; j++, i++) {
                dp[i][j] = (dp[i+1][j-1] == 1 && (s.charAt(i) == s.charAt(j))) == true ? 1 : 0;
                ans += dp[i][j];
            }
        }
        return ans;
    }
}