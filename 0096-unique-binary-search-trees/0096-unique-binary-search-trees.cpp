class Solution {
public:
    int numTrees(int n) {
        // F(i, n) : no of unique BST where i is the root and number ranges from 1 .. n
        // G(n) : No of unique BST of length n
        // we can say G(n) = F(1, n) + F(2, n) + ... F(n, n);
        // F(3, 7)  array = [1, 2, 3(root), 4, 5, 6, 7]
        // F(3, 7) : G(2) - {1, 2} * G(4) - {4, 5, 6, 7}
        // F(i, n) = G(i-1) * G(n-i)
        // G(n) : G(n) = G(0) * G(n-1) + G(1) * G(n-2) + … + G(n-1) * G(0) 
        vector<int>dp(n+1, 0);
        dp[0] = dp[1] = 1;
        for(int i=2; i<=n; i++) {
            for(int j=0; j<i; j++) {
                dp[i] += dp[j] * dp[i-1-j];
            }
        }
        return dp[n];
    }
    int solve(int n, vector<int>&dp) {
        if(n <= 1) return 1;
        if(dp[n] != -1) return dp[n];
        int res = 0;
        for(int i=0; i<n; i++) {
            res += solve(i, dp) * solve(n-1-i, dp); 
        }
        return dp[n] = res;
    }
};