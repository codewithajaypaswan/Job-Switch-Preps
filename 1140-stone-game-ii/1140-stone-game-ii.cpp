class Solution {
public:
    int solve(vector<int>&piles, int ind, int M, vector<vector<int>>&dp) {
        if(ind >= piles.size()) return 0;
        if(dp[ind][M] != -1) return dp[ind][M];
        int total = 0, ans = INT_MIN;
        for(int i=0; i<2*M; i++) {
            if(ind + i < piles.size()) total += piles[ind + i];
            ans = max(ans, total - solve(piles, ind + i + 1, max(M, i+1), dp));
        }
        return dp[ind][M] = ans;
    }
    int stoneGameII(vector<int>& piles) {
        int n = piles.size();
        vector<vector<int>>dp(101, vector<int>(101, -1));
        int sum = 0;
        for(int p:piles) {
            sum += p;
        }
        int diff = solve(piles, 0, 1, dp);
        return (sum + diff)/2;
    }
};
// a = stones picked by Alice
// b = stones picked by Bob
// a+b == total stones
// a-b == diff stones
// ans = (a+b) + (a-b) == 2a
// return ans/2