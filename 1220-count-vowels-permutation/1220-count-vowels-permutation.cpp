class Solution {
public:
    int mod = 1e9+7;
    unordered_map<string, int>mp;
    int countVowelPermutation(int n) {
        // char ch[5] = {'a', 'e', 'i', 'o', 'u'};
        // long ans = 0;
        // for(int i=0; i<5; i++) {
        //     ans = (ans%mod + solve(n-1, ch[i]))%mod;
        // }
        // return ans;
        
        vector<vector<long>>dp(n, vector<long>(5, 0));
        for(int i=0; i<5; i++) {
            dp[n-1][i] = 1;
        }
        for(int i=n-2; i>=0; i--) {
            dp[i][0] = (dp[i+1][1])%mod;
            dp[i][1] = (dp[i+1][0]%mod + dp[i+1][2])%mod;
            dp[i][2] = (dp[i+1][0]%mod + dp[i+1][1]%mod + dp[i+1][3]%mod + dp[i+1][4]%mod)%mod;
            dp[i][3] = (dp[i+1][2]%mod + dp[i+1][4]%mod);
            dp[i][4] = (dp[i+1][0])%mod;
        }
        long ans = 0;
        for(int i=0; i<5; i++) {
            ans = (ans + dp[0][i])%mod;
        }
        return ans;
    }
    int solve(int remChar, char curChar) {
        if(remChar == 0) return 1;
        string key = to_string(remChar) + "*" + curChar;
        if(mp.find(key) != mp.end()) return mp[key];
        long ans = 0;
        if(curChar == 'a') {
            ans = (ans%mod + solve(remChar-1, 'e')%mod)%mod;
        }
        else if(curChar == 'e') {
            ans = (ans%mod + solve(remChar-1, 'a')%mod + solve(remChar-1, 'i')%mod)%mod;
        }
        else if(curChar == 'i') {
            ans = (ans%mod + solve(remChar-1, 'a')%mod + solve(remChar-1, 'e')%mod + solve(remChar-1, 'o')%mod + solve(remChar-1, 'u')%mod)%mod;
        }
        else if(curChar == 'o') {
            ans = (ans%mod + solve(remChar-1, 'i')%mod + solve(remChar-1, 'u')%mod)%mod;
        }
        else {
            ans = (ans%mod + solve(remChar-1, 'a')%mod)%mod;
        }
        return mp[key] = ans;
    }
};