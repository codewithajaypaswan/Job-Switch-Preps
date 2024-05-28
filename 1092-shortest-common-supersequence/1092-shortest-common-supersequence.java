class Solution {
    public String findLCS(String str1, String str2) {
        int n = str1.length(), m = str2.length();
        int[][] dp = new int[n+1][m+1];
        for(int i=1; i<=n; i++) {
            for(int j=1; j<=m; j++) {
                if(str1.charAt(i-1) == str2.charAt(j-1)) {
                    dp[i][j] = 1 + dp[i-1][j-1];
                }
                else {
                    dp[i][j] = Math.max(dp[i-1][j], dp[i][j-1]);
                }
            }
        }
        StringBuilder sb = new StringBuilder();
        int i = n, j = m;
        while(i >= 1 && j >= 1) {
            if(str1.charAt(i-1) == str2.charAt(j-1)) {
                sb.append(str1.charAt(i-1));
                i--; j--;
            }
            else if(dp[i-1][j] > dp[i][j-1]) i--;
            else j--;
        }
        sb = sb.reverse();
        return sb.toString();
    }
    public String shortestCommonSupersequence(String str1, String str2) {
        String str = findLCS(str1, str2);
        StringBuilder sb = new StringBuilder();
        int i = 0, j = 0;
        int n = str1.length(), m = str2.length();
        for(char c:str.toCharArray()) {
            while(i < n && str1.charAt(i) != c) {
                sb.append(str1.charAt(i));
                i++;
            }
            while(j < m && str2.charAt(j) != c) {
                sb.append(str2.charAt(j));
                j++;
            }
            sb.append(c);
            i++; j++;
        }
        return sb.toString() + str1.substring(i) + str2.substring(j);
    }
}