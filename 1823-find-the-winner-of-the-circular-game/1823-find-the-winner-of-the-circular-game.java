class Solution {
    int solve(int n, int k) {
        if(n == 1) return 0;
        return (solve(n-1, k) + k)%n;
    }
    public int findTheWinner(int n, int k) {
        int ans = 0;
        for(int i=1; i<=n; i++) {
            ans = (ans + k)%i;
        }
        return ans + 1;
    }
}