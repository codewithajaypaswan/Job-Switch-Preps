class Solution {
public:
    int dp[2][501][501];
    bool stoneGame(vector<int>& piles) {
        memset(dp, -1, sizeof(dp));
        int n = piles.size();
        return solve(piles, 0, n-1, 1) > 0;
    }
    int solve(vector<int>&piles, int i, int j, int person) {
        if(i > j) return 0;
        if(dp[person][i][j] != -1) return dp[person][i][j];
        if(person == 1) {
            // Alice should maximize the score
            dp[person][i][j] = max(piles[i] - solve(piles, i+1, j, 0), piles[j] - solve(piles, i, j-1, 0));
        }
        else {
            dp[person][i][j] = min(-piles[i] - solve(piles, i+1, j, 1), -piles[j] - solve(piles, i, j-1, 1));
        }
        return dp[person][i][j];
    }
};