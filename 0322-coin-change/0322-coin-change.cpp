class Solution {
public:
    int solve(vector<int>&coins, int amount, vector<int>&dp) {
        if(amount == 0) return 0;
        if(amount < 0) return 1e9;
        if(dp[amount] != -1) return dp[amount];
        int ans = 1e9;
        for(int i=0; i<coins.size(); i++) {
            ans = min(ans, 1 + solve(coins, amount - coins[i], dp));
        }
        return dp[amount] = ans;
    }
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        vector<int>dp(amount+1, 1e9);
        dp[0] = 0;
        for(auto coin:coins) {
            for(int i=coin; i<=amount; i++) {
                dp[i] = min(dp[i], dp[i - coin] + 1);
            }
        }
        return dp[amount] == 1e9 ? -1 : dp[amount];
    }
};