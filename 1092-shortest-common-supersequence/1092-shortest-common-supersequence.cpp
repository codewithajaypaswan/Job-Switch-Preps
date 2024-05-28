class Solution {
public:
    string findLCS(string &s1, string &s2) {
        int n = s1.size(), m = s2.size();
        vector<vector<int>>dp(n+1, vector<int>(m+1, 0));
        for(int i=1; i<=n; i++) {
            for(int j=1; j<=m; j++) {
                if(s1[i-1] == s2[j-1]) {
                    dp[i][j] = 1 + dp[i-1][j-1];
                }
                else {
                    dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
                }
            }
        }
        string ans = "";
        int i = n, j = m;
        while(i >= 1 && j >= 1) {
            if(s1[i-1] == s2[j-1]) {
                ans += s1[i-1];
                i--; j--;
            }
            else if(dp[i-1][j] > dp[i][j-1]) {
                i--;
            }
            else {
                j--;
            }
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
    string shortestCommonSupersequence(string str1, string str2) {
        string str = findLCS(str1, str2);
        string ans = "";
        int i = 0, j = 0, k = 0;
        for(char c:str) {
            while(i < str1.size() && str1[i] != c) ans += str1[i++];
            while(j < str2.size() && str2[j] != c) ans += str2[j++];
            ans += c;
            i++; j++;
        }
        ans = ans + str1.substr(i) + str2.substr(j);
        return ans;
    }
};