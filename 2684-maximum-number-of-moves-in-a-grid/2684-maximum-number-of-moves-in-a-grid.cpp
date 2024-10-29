class Solution {
public:
    int maxMoves(vector<vector<int>>& grid) {
        int ans = 0, n = grid.size(), m = grid[0].size();
        vector<vector<int>>dp(n, vector<int>(m, -1));
        for(int i=0; i<grid.size(); i++) {
            ans = max(ans, solve(grid, i, 0, dp));
        }
        return ans;
    }
    int solve(vector<vector<int>>&grid, int row, int col, vector<vector<int>>&dp) {
        int case1 = 0, case2 = 0, case3 = 0;
        int n = grid.size(), m = grid[0].size();
        if(dp[row][col] != -1) return dp[row][col];
        if(row+1 < n && col+1 < m && grid[row][col] < grid[row+1][col+1]) {
            case1 += 1 + solve(grid, row+1, col+1, dp);
        }
        if(row < n && col+1 < m && grid[row][col] < grid[row][col+1]) {
            case2 += 1 + solve(grid, row, col+1, dp);
        }
        if(row-1 >= 0 && col+1 < m && grid[row][col] < grid[row-1][col+1]) {
            case3 += 1 + solve(grid, row-1, col+1, dp);
        }
        int ans = max({case1, case2, case3});
        return dp[row][col] = ans;
    }
    
};