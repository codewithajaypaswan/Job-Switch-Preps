class Solution {
    public int numTrees(int n) {
        // F(i, n) : no of unique BST where i is the root and number ranges from 1 .. n
        // G(n) : No of unique BST of length n
        // we can say G(n) = F(1, n) + F(2, n) + ... F(n, n);
        // F(3, 7)  array = [1, 2, 3(root), 4, 5, 6, 7]
        // F(3, 7) : G(2) - {1, 2} * G(4) - {4, 5, 6, 7}
        // G(n) : F(n-1) * F(0) + F(n-2) * F(1) + F(n-3) * F(2) + .... F(0) * F(n-1)
        int[] dp = new int[n+1];
        Arrays.fill(dp, -1);
        return solve(n, dp);
    }
    private int solve(int n, int[] dp) {
        if(n <= 1) return 1;
        if(dp[n] != -1) return dp[n];
        int res = 0;
        for(int i=0; i<n; i++) {
            res += solve(i, dp) * solve(n-1-i, dp);
        }
        return dp[n] = res;
    }
}