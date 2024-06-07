class Solution {
public:
    int dp[2][101][101];
    int solveForAlice(int person, int ind, int M, vector<int>&piles) {
        if(ind >= piles.size()) return 0;
        if(dp[person][ind][M] != -1) return dp[person][ind][M];
        int ans = person == 1 ? INT_MIN : INT_MAX;
        int stones = 0;
        for(int x=1; x<=2*M; x++) {
            if(ind + x - 1 >= piles.size()) break;
            stones += piles[ind+x-1];
            if(person == 1) {
                // for alice we maximize the result
                ans = max(ans, stones + solveForAlice(0, ind+x, max(M, x), piles));
            }
            else {
                // for bob we minimize the result
                ans = min(ans, solveForAlice(1, ind+x, max(M, x), piles));
            }
        }
        return dp[person][ind][M] = ans;
    }
    int stoneGameII(vector<int>& piles) {
        memset(dp, -1, sizeof(dp));
        return solveForAlice(1, 0, 1, piles);
    }
};